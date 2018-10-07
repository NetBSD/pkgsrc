$NetBSD: patch-src_rblsmtpd.c,v 1.1 2018/10/07 12:55:16 schmonz Exp $

Avoid conflicting with wait(2).

--- src/rblsmtpd.c.orig	2018-08-16 13:47:56.000000000 +0000
+++ src/rblsmtpd.c
@@ -152,7 +152,7 @@ static stralloc info;
 char inspace[64]; buffer in = BUFFER_INIT(read,0,inspace,sizeof(inspace));
 char outspace[1]; buffer out = BUFFER_INIT(write,1,outspace,sizeof(outspace));
 
-void wait(unsigned long delay)
+void dowait(unsigned long delay)
 {
   unsigned long u;
   char *x;
@@ -297,8 +297,8 @@ int main(int argc,char **argv,char **env
       case 't': scan_ulong(optarg,&timeout); break;
       case 'r': rbl(optarg); break;
       case 'a': antirbl(optarg); break;
-      case 'W': if (!decision) { wait(greetdelay); } break;
-      case 'w': if (!decision) { scan_ulong(optarg,&greetdelay); wait(greetdelay); } break;
+      case 'W': if (!decision) { dowait(greetdelay); } break;
+      case 'w': if (!decision) { scan_ulong(optarg,&greetdelay); dowait(greetdelay); } break;
       default: usage();
     }
 
