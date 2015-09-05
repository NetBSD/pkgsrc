$NetBSD: patch-src_log__format.hh,v 1.1 2015/09/05 22:12:04 wiz Exp $

To avoid this error on NetBSD:
In file included from logfile.hh:47:0,
                 from logfile.cc:47:
log_format.hh: In member function 'const string logline_value::to_string() const':
log_format.hh:411:50: error: expected ')' before 'PRId64'
             snprintf(buffer, sizeof(buffer), "%" PRId64, this->lv_number.i);
                                                  ^
log_format.hh:411:75: warning: spurious trailing '%' in format [-Wformat=]
             snprintf(buffer, sizeof(buffer), "%" PRId64, this->lv_number.i);
                                                                           ^
log_format.hh:411:75: warning: too many arguments for format [-Wformat-extra-args]
log_format.hh:411:75: warning: spurious trailing '%' in format [-Wformat=]
log_format.hh:411:75: warning: too many arguments for format [-Wformat-extra-args]

--- src/log_format.hh.orig	2015-04-11 05:56:05.000000000 +0000
+++ src/log_format.hh
@@ -408,7 +408,7 @@ public:
             }
 
         case VALUE_INTEGER:
-            snprintf(buffer, sizeof(buffer), "%" PRId64, this->lv_number.i);
+            snprintf(buffer, sizeof(buffer), "%ld", this->lv_number.i);
             break;
 
         case VALUE_FLOAT:
