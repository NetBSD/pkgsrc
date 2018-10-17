#!/bin/sh
#
# Sample TSM startup file, adjust to your requirements and
# call from e.g /etc/daily.local
#
# Daily (nightly) backup via Tivoli Storage Manager (IBM ADSM)
# Set up environment, wrap logfiles and start dsmc.
#
# NetBSD configuration hints:
#
#  - TSM expects ${EMULDIR}/etc/mtab to exist and be meaningful. The current 
#    suse91_base package sets up a symlink to ${EMULDIR}/proc/mounts which 
#    works on NetBSD 3 if you mount procfs in /etc/fstab like
#
#      procfs  /emul/linux/proc  procfs  ro,linux  0 0
#
#    Alternatively, make ${EMULDIR}/etc/mtab a symlink to /etc/fstab.
#  - Make sure 'passworddir' is set in tsm.sys so that the passwd file
#    ends up in ${PKG_SYSCONFDIR} instead of the shadow hierarchy.
#  - The environment variables DSM_DIR, DSM_CONFIG, DSM_LOG 
#    need to be set properly. DSM_LOG may inadvertently end up in 
#    the emul shadow hierarchy.
#  - For backing up the native filesystem hierarchy, prefix paths with 
#    '/../', or use a construct like "ln -s / /.`hostname`" to break 
#    out of the emul shadow hierarchy.
#
# $NetBSD: tsm_daily.sh,v 1.1 2018/10/17 13:54:39 hauke Exp $

umask 027

# Adapt to your pkgsrc settings
SYSCONFDIR="%PKG_SYSCONFDIR%"
PREFIX="%PREFIX%"
VARBASE="%VARBASE%"

TSMCONFDIR="${SYSCONFDIR}"
TSMBINDIR="${PREFIX}/emul/linux/opt/tivoli/tsm/client/ba/bin"

DSM_DIR="${PREFIX}/emul/linux/opt/tivoli/tsm/client/ba/bin"
DSM_CONFIG="${TSMCONFDIR}/dsm.opt"
DSM_LOG="${VARBASE}/log"

export DSM_DIR DSM_CONFIG DSM_LOG 

# Check if the above settings are reasonable
if [ ! -d ${TSMCONFDIR} ]
then
    echo "TSM config directory ${TSMCONFDIR} does not exist, aborting." | logger
    exit 1
elif [ ! -f ${DSM_CONFIG} ]
then
    echo "TSM config file ${DSM_CONFIG} not found, aborting." | logger
    exit 1
fi

LC_CTYPE="en_US"
LC_ALL="en_US"
LANG="en_US"

export LC_CTYPE LC_ALL LANG


LOGNAME="dsm-runlog"

# Rotate the logs
for ii in 5 4 3 2 1 0
do
    if [ -f ${DSM_LOG}/${LOGNAME}.${ii} ]
    then
	mv ${DSM_LOG}/${LOGNAME}.${ii} ${DSM_LOG}/${LOGNAME}.$((${ii} + 1))
    fi
done

if [ -f ${DSM_LOG}/${LOGNAME} ]
then
    mv ${DSM_LOG}/${LOGNAME} ${DSM_LOG}/${LOGNAME}.0
fi

echo "DSM Daily Backup start: " `date` | logger

DSMC=${TSMBINDIR}/dsmc

${DSMC} incremental > ${DSM_LOG}/${LOGNAME} 2>&1

echo "DSM Daily Backup finished: " `date` | logger
