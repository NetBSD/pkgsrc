--- makeip.c.orig	2000-09-05 11:56:58.000000000 -0700
+++ makeip.c	2018-11-30 08:24:17.000000000 -0800
@@ -74,7 +74,7 @@ int parse_input(FILE *fh, char *ip)
   while(fgets(buf, sizeof(buf), fh)) {
     char *p;
     trim(buf);
-    if(*buf)
+    if(*buf) {
       if((p = strchr(buf, ':'))) {
 	*p++ = '\0';
 	trim(buf);
@@ -89,7 +89,7 @@ int parse_input(FILE *fh, char *ip)
 	while(*p == ' ' || *p == '\t')
 	  p++;
 	if(strlen(p)>fields[i].len) {
-	  fprintf(stderr, "Data for field \"%s\" is too long.\n", fields[i]);
+	  fprintf(stderr, "Data for field \"%s\" is too long.\n", fields[i].name);
 	  return 0;
 	}
 	memcpy(ip+fields[i].pos, p, strlen(p));
@@ -101,11 +101,12 @@ int parse_input(FILE *fh, char *ip)
 	fprintf(stderr, "Missing : on line.\n");
 	return 0;
       }
+    }
   }
 
   for(i=0; i<NUM_FIELDS; i++)
     if(!filled_in[i]) {
-      fprintf(stderr, "Missing value for \"%s\".\n", fields[i]);
+      fprintf(stderr, "Missing value for \"%s\".\n", fields[i].name);
       return 0;
     }
       
@@ -183,7 +184,7 @@ int main(int argc, char *argv[])
 
   ip_tmpl = getenv("IP_TEMPLATE_FILE");
   if(ip_tmpl == NULL)
-    ip_tmpl = "IP.TMPL";
+    ip_tmpl = "/usr/local/pkg/share/dc-tools/IP.TMPL";
 
   makeip(ip_tmpl, argv[1], argv[2]);
 
