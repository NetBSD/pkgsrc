$NetBSD: patch-cli_src_cli-xml-output.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

Avoid wrong-size integer casts and fix format string.

--- cli/src/cli-xml-output.c.orig	2020-09-16 18:40:32.172503539 +0000
+++ cli/src/cli-xml-output.c
@@ -1661,8 +1661,8 @@ cli_xml_output_vol_top_rw_perf(xmlTextWr
     int ret = -1;
     char *filename = NULL;
     uint64_t throughput = 0;
-    long int time_sec = 0;
-    long int time_usec = 0;
+    int32_t time_sec = 0;
+    int32_t time_usec = 0;
     char timestr[256] = {
         0,
     };
@@ -1692,18 +1692,18 @@ cli_xml_output_vol_top_rw_perf(xmlTextWr
     XML_RET_CHECK_AND_GOTO(ret, out);
 
     snprintf(key, sizeof(key), "%d-time-sec-%d", brick_index, member_index);
-    ret = dict_get_int32(dict, key, (int32_t *)&time_sec);
+    ret = dict_get_int32(dict, key, &time_sec); /* XXX Y2038 bug? */
     if (ret)
         goto out;
 
     snprintf(key, sizeof(key), "%d-time-usec-%d", brick_index, member_index);
-    ret = dict_get_int32(dict, key, (int32_t *)&time_usec);
+    ret = dict_get_int32(dict, key, &time_usec);
     if (ret)
         goto out;
 
     gf_time_fmt(timestr, sizeof timestr, time_sec, gf_timefmt_FT);
     len = strlen(timestr);
-    snprintf(timestr + len, sizeof(timestr) - len, ".%" GF_PRI_SUSECONDS,
+    snprintf(timestr + len, sizeof(timestr) - len, ".%" PRIu32,
              time_usec);
     ret = xmlTextWriterWriteFormatElement(writer, (xmlChar *)"time", "%s",
                                           timestr);
