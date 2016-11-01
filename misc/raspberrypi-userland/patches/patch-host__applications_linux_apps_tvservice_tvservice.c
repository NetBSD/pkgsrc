$NetBSD: patch-host__applications_linux_apps_tvservice_tvservice.c,v 1.1 2016/11/01 16:45:28 skrll Exp $

--- host_applications/linux/apps/tvservice/tvservice.c.orig	2016-11-01 11:58:40.068142335 +0000
+++ host_applications/linux/apps/tvservice/tvservice.c
@@ -426,7 +426,7 @@ static const char *status_mode( TV_DISPL
          }
       }
       //This is the format's aspect ratio
-      tmp = status_sprintf(mode_str, MAX_STATUS_STR_LENGTH, &offset, " %s", aspect_ratio_sd_str(tvstate->display.sdtv.display_options.aspect));
+      tmp = status_sprintf(mode_str, MAX_STATUS_STR_LENGTH, &offset, " %s", aspect_ratio_str(tvstate->display.sdtv.display_options.aspect));
    } else if (tvstate->state & VC_LCD_ATTACHED_DEFAULT) {
       status_sprintf(mode_str, MAX_STATUS_STR_LENGTH, &offset, "LCD");
    } else {
