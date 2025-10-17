$NetBSD: patch-client-src_rundump.c,v 1.1 2025/10/17 07:55:17 kikadf Exp $

* Fix CVE-2022-37704,
  https://github.com/zmanda/amanda/commit/ee766efdd77acd2e08f646bf2f9028944cdb9d06

--- client-src/rundump.c.orig	2025-10-17 07:37:52.952255055 +0000
+++ client-src/rundump.c
@@ -39,6 +39,8 @@
 #include "conffile.h"
 
 int main(int argc, char **argv);
+static void validate_dump_option(int argc, char ** argv);
+static void validate_xfsdump_options(int argc, char ** argv);
 
 #if defined(VDUMP) || defined(XFSDUMP)
 #  undef USE_RUNDUMP
@@ -154,14 +156,17 @@ main(
 
 #if defined(DUMP)
         dump_program = DUMP;
+        validate_dump_option(argc, argv);
 #else
 # if defined(XFSDUMP)
         dump_program = XFSDUMP;
+        validate_xfsdump_options(argc, argv);
 # else
 #  if defined(VXDUMP)
 	dump_program = VXDUMP;
 #  else
         dump_program = "dump";
+        validate_dump_option(argc, argv);
 #  endif
 # endif
 #endif
@@ -187,3 +192,133 @@ main(
     return 1;
 #endif								/* } */
 }
+
+void validate_dump_option(int argc, char ** argv)
+{
+	int c;
+	int numargs = argc;
+	while (numargs > 0)
+	{
+		c = getopt(argc, argv, "0123456789ab:cd:e:f:h:j:kmnqs:uvwyz:A:B:D:I:L:MQ:ST:W");
+		switch (c) {
+			case -1:
+				optind++;
+			break;
+			case '?':
+				//option is not valid
+				error("error [%s invalid option: %s]\n", get_pname(), argv[optind-1]);
+			break;
+			// All this options takes another argument
+			case 'b':
+			case 'd':
+			case 'e':
+			case 'f':
+			case 'h':
+			case 'j':
+			case 's':
+			case 'z':
+			case 'A':
+			case 'B':
+			case 'D':
+			case 'I':
+			case 'L':
+			case 'Q':
+			case 'T':
+			{
+				// get optarg and check it against NULL. If it is null, then return error.
+				if (optarg == NULL) {
+					error ("error [%s additional parameter is missing for option: %c]\n", get_pname(), c);
+				}
+				break;
+			}
+			case '0':
+			case '1':
+			case '2':
+			case '3':
+			case '4':
+			case '5':
+			case '6':
+			case '7':
+			case '8':
+			case '9':
+			case 'a':
+			case 'c':
+			case 'k':
+			case 'm':
+			case 'n':
+			case 'q':
+			case 'u':
+			case 'v':
+			case 'w':
+			case 'y':
+			case 'M':
+			case 'S':
+			case 'W':
+			{
+				break;
+			}
+			default:
+				error ("error [%s invalid option: %c]\n", get_pname(), c);
+			break;
+		}
+		numargs--;
+	}
+}
+
+void validate_xfsdump_options(int argc, char ** argv)
+{
+	int c;
+	int numargs = argc;
+	while (numargs > 0)
+	{
+		c = getopt(argc, argv, "ab:d:ef:l:mop:qs:t:v:z:AB:DFI:JL:M:RT");
+		switch (c) {
+			case -1:
+				optind++;
+			break;
+			case '?':
+				//option is not valid
+				error ("error [%s invalid option: %s]\n", get_pname(), argv[optind-1]);
+			break;
+			// All this options takes another argument
+			case 'b':
+			case 'd':
+			case 'f':
+			case 'l':
+			case 'p':
+			case 's':
+			case 't':
+			case 'v':
+			case 'z':
+			case 'B':
+			case 'I':
+			case 'L':
+			case 'M':
+			{
+				// get optarg and check it against NULL. If it is null, then return error.
+				if (optarg == NULL) {
+					error ("error [%s additional parameter is missing for option: %c]\n", get_pname(), c);
+				}
+				break;
+			}
+			case 'a':
+			case 'e':
+			case 'm':
+			case 'o':
+			case 'q':
+			case 'A':
+			case 'D':
+			case 'F':
+			case 'J':
+			case 'R':
+			case 'T':
+			{
+				break;
+			}
+			default:
+				error ("error [%s invalid option: %c]\n", get_pname(), c);
+			break;
+		}
+		numargs--;
+	}
+}
