#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <prop/proplib.h>
#include <sys/envsys.h>

#include "apm.h"
#include "envsys.h"

#define _DEV_SYSMON "/dev/sysmon"

int
envsys_supported (void)
{
   return 1; /* XXX */
}

prop_array_t
get_device (const char * name)
{
    prop_dictionary_t sys_dict;
    prop_array_t array;
    int smfd;

    if (name == NULL)
        return NULL;

    smfd = open (_DEV_SYSMON, O_RDONLY);
    if (smfd == -1)
        return NULL;

    if (prop_dictionary_recv_ioctl (smfd,
                                    ENVSYS_GETDICTIONARY,
                                    &sys_dict) != 0)
    {
        return NULL;
    }

    close (smfd);

    array = prop_dictionary_get (sys_dict, name);
    if (array == NULL)
        return NULL;

    prop_object_retain (array);
    prop_object_release (sys_dict);

    return array;
}

bool
stat_is_valid (prop_dictionary_t stat)
{
    prop_string_t strval;

    if (stat == NULL)
        return false;

    strval = prop_dictionary_get (stat, "state");
    if (strval == NULL)
        return false;
    

    return prop_string_equals_cstring (strval, "valid");
}

int64_t
handle_stat (prop_dictionary_t stat,
             const char * key)
{
    prop_number_t numval;

    if (stat == NULL || key == NULL)
        return -1;

    numval = (prop_number_t) prop_dictionary_get (stat, key);
    if (numval == NULL)
        return -1;

    return prop_number_integer_value (numval);
}

int
envsys_read (int battery,
             apm_info *info)
{
    prop_object_iterator_t iter;
    prop_dictionary_t id;
    prop_string_t desc;
    prop_array_t bat_info, ac_info;
    bool is_present = false;
    int64_t charge_rate = 0,
            max_charge = 0,
            cur_charge = 0,
            warn_charge = 0,
            crit_charge = 0;
    char dev_name[32];
    int bat_id = battery - 1;

    if (info == NULL || (battery - 1 < 0))
        return -1;

    info->battery_flags = 0;
    info->using_minutes = 1;

    snprintf (dev_name, sizeof (dev_name), "acpibat%d", bat_id);

    bat_info = get_device (dev_name);
    if (bat_info == NULL)
        return -1;

    ac_info = get_device ("acpiacad0");
    if (ac_info != NULL) {
        iter = prop_array_iterator (ac_info);
        while ((id = (prop_dictionary_t) prop_object_iterator_next (iter)) != NULL)
        {
            desc = (prop_string_t) prop_dictionary_get (id, "description");
            if (desc == NULL) continue;
            if (!prop_string_equals_cstring (desc, "connected"))
                continue;
            if (handle_stat (id, "cur-value") != 0) {
                info->ac_line_status = AC_LINE_STATUS_ON;
            } else {
                info->ac_line_status = AC_LINE_STATUS_OFF;
            }
            break;
        }
        prop_object_iterator_release (iter);
        prop_object_release (ac_info);
    } else {
        info->ac_line_status = AC_LINE_STATUS_UNKNOWN;
    }

    iter = prop_array_iterator (bat_info);
    while ((id = (prop_dictionary_t) prop_object_iterator_next (iter)) != NULL)
    {
        desc = (prop_string_t) prop_dictionary_get (id, "description");
        if (desc == NULL) continue;
        if (prop_string_equals_cstring (desc, "charge")) {
            cur_charge = handle_stat (id, "cur-value");
            max_charge = handle_stat (id, "max-value");
            warn_charge = handle_stat (id, "warning-capacity");
            crit_charge = handle_stat (id, "critical-capacity");
        } else if (prop_string_equals_cstring (desc, "charge rate")) {
            if (stat_is_valid (id)) charge_rate = handle_stat (id, "cur-value");
        } else if (prop_string_equals_cstring (desc, "discharge rate")) {
            if (stat_is_valid (id)) charge_rate = handle_stat (id, "cur-value");
        } else if (prop_string_equals_cstring (desc, "present")) {
            is_present = (handle_stat (id, "cur-value") == 1);
        }
    }
    prop_object_iterator_release (iter);
    prop_object_release (bat_info);

    if (max_charge > 1) {
        info->battery_percentage = ( cur_charge * 100 ) / max_charge;
        if (info->battery_percentage > 100) info->battery_percentage = 100;
    } else {
        info->battery_percentage = BATTERY_PERCENTAGE_UNKNOWN;
    }

    if (info->ac_line_status) {
        info->battery_status = BATTERY_STATUS_CHARGING;
        /*
         * If our charge rate is 0, then it was either marked invalid by envsys
         * or we're "charging" at 0Wh-- either way, the battery isn't charging
         */ 
        if (charge_rate > 0) {
            info->battery_flags = info->battery_flags | BATTERY_FLAGS_CHARGING;
        }
    } else {
        if (cur_charge < crit_charge) {
            info->battery_status = BATTERY_STATUS_CRITICAL;
        } else if (cur_charge < warn_charge) {
            info->battery_status = BATTERY_STATUS_LOW;
        } else {
            info->battery_status = BATTERY_STATUS_HIGH;
        }
    }

    if (!is_present) {
        info->battery_percentage = 0;
        info->battery_time = 0;
        info->battery_status = BATTERY_STATUS_ABSENT;
    }

    /* calculate time remaining */
    if (charge_rate == 0) {
        info->battery_time = BATTERY_TIME_UNKNOWN;
    } else {
        info->battery_time = ( (max_charge - cur_charge) * 60) / charge_rate;
    }

    return 0;
}
