$NetBSD: patch-items.c,v 1.3 2019/09/05 09:34:51 adam Exp $

time_t changes

--- items.c.orig	2019-08-29 22:13:13.000000000 +0000
+++ items.c
@@ -606,10 +606,10 @@ char *item_cachedump(const unsigned int 
         /* Copy the key since it may not be null-terminated in the struct */
         strncpy(key_temp, ITEM_key(it), it->nkey);
         key_temp[it->nkey] = 0x00; /* terminate */
-        len = snprintf(temp, sizeof(temp), "ITEM %s [%d b; %llu s]\r\n",
+        len = snprintf(temp, sizeof(temp), "ITEM %s [%d b; %jd s]\r\n",
                        key_temp, it->nbytes - 2,
                        it->exptime == 0 ? 0 :
-                       (unsigned long long)it->exptime + process_started);
+                       (intmax_t)it->exptime + process_started);
         if (bufcurr + len + 6 > memlimit)  /* 6 is END\r\n\0 */
             break;
         memcpy(buffer + bufcurr, temp, len);
@@ -787,14 +787,14 @@ void item_stats(ADD_STAT add_stats, void
             APPEND_NUM_FMT_STAT(fmt, n, "age_hot", "%u", age_hot);
             APPEND_NUM_FMT_STAT(fmt, n, "age_warm", "%u", age_warm);
         }
-        APPEND_NUM_FMT_STAT(fmt, n, "age", "%u", age);
+        APPEND_NUM_FMT_STAT(fmt, n, "age", "%jd", age);
         APPEND_NUM_FMT_STAT(fmt, n, "mem_requested", "%llu", (unsigned long long)totals.mem_requested);
         APPEND_NUM_FMT_STAT(fmt, n, "evicted",
                             "%llu", (unsigned long long)totals.evicted);
         APPEND_NUM_FMT_STAT(fmt, n, "evicted_nonzero",
                             "%llu", (unsigned long long)totals.evicted_nonzero);
         APPEND_NUM_FMT_STAT(fmt, n, "evicted_time",
-                            "%u", totals.evicted_time);
+                            "%jd", totals.evicted_time);
         APPEND_NUM_FMT_STAT(fmt, n, "outofmemory",
                             "%llu", (unsigned long long)totals.outofmemory);
         APPEND_NUM_FMT_STAT(fmt, n, "tailrepairs",
