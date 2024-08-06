$NetBSD: patch-cli_src_cli-xml-output.c,v 1.3 2024/08/06 21:10:47 riastradh Exp $

Fix time type cast abuse.

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- cli/src/cli-xml-output.c.orig	2023-04-06 09:01:24.673967239 +0000
+++ cli/src/cli-xml-output.c
@@ -1661,6 +1661,8 @@ cli_xml_output_vol_top_rw_perf(xmlTextWr
     int ret = -1;
     char *filename = NULL;
     uint64_t throughput = 0;
+    int32_t time_sec;
+    int32_t time_usec;
     struct timeval tv = {
         0,
     };
@@ -1692,14 +1694,16 @@ cli_xml_output_vol_top_rw_perf(xmlTextWr
     XML_RET_CHECK_AND_GOTO(ret, out);
 
     snprintf(key, sizeof(key), "%d-time-sec-%d", brick_index, member_index);
-    ret = dict_get_int32(dict, key, (int32_t *)&tv.tv_sec);
+    ret = dict_get_int32(dict, key, &time_sec); /* XXX Y2038 bug? */
     if (ret)
         goto out;
+    tv.tv_sec = time_sec;
 
     snprintf(key, sizeof(key), "%d-time-usec-%d", brick_index, member_index);
-    ret = dict_get_int32(dict, key, (int32_t *)&tv.tv_usec);
+    ret = dict_get_int32(dict, key, &time_usec);
     if (ret)
         goto out;
+    tv.tv_usec = time_usec;
 
     gf_time_fmt_tv(timestr, sizeof timestr, &tv, gf_timefmt_FT);
     ret = xmlTextWriterWriteFormatElement(writer, (xmlChar *)"time", "%s",
@@ -3413,7 +3417,7 @@ _output_gsync_config(FILE *fp, xmlTextWr
             break;
 
         v = resbuf + strlen(resbuf) - 1;
-        while (isspace(*v)) {
+        while (isspace((unsigned char)*v)) {
             /* strip trailing space */
             *v-- = '\0';
         }
@@ -3435,7 +3439,7 @@ _output_gsync_config(FILE *fp, xmlTextWr
             goto out;
         }
         *v++ = '\0';
-        while (isspace(*v))
+        while (isspace((unsigned char)*v))
             v++;
         v = gf_strdup(v);
         if (!v) {
