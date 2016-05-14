$NetBSD: patch-imap_src_mtest_mtest.c,v 1.2 2016/05/14 16:13:10 bsiegert Exp $

- patch up buffer handling (required to build on openbsd)

--- imap/src/mtest/mtest.c.orig	2015-01-12 05:12:25.000000000 +0000
+++ imap/src/mtest/mtest.c
@@ -151,6 +151,7 @@ void mm (MAILSTREAM *stream,long debug)
   void *sdb = NIL;
   char cmd[MAILTMPLEN],tmp[MAILTMPLEN];
   char *s, *arg;
+  size_t argmax;
   unsigned long i;
   unsigned long last = 0;
   BODY *body;
@@ -158,7 +159,9 @@ void mm (MAILSTREAM *stream,long debug)
   while (stream) {
     prompt ("MTest> ",cmd, sizeof(cmd)); /* prompt user, get command */
 				/* get argument */
-    if (arg = strchr (cmd,' ')) *arg++ = '\0';
+    if (arg)
+      argmax = sizeof(cmd) - (arg - cmd);
+
     switch (*ucase (cmd)) {	/* dispatch based on command */
     case 'B':			/* Body command */
       if (arg) last = atoi (arg);
@@ -185,7 +188,8 @@ void mm (MAILSTREAM *stream,long debug)
 	  break;
 	}
 	arg = cmd;
-	sprintf (arg,"%lu",last);
+	argmax = sizeof(cmd);
+	snprintf (arg, argmax, "%lu",last);
       }
       if (last && (last <= stream->nmsgs))
 	mail_setflag (stream,arg,"\\DELETED");
@@ -198,6 +202,7 @@ void mm (MAILSTREAM *stream,long debug)
     case 'F':			/* Find command */
       if (!arg) {
 	arg = "%";
+	argmax = 0;
 	if (s = sm_read (tmp,&sdb)) {
 	  puts ("Local network subscribed mailboxes:");
 	  do if (*s == '{') (mm_lsub (NIL,NIL,s,NIL));
@@ -251,7 +256,7 @@ void mm (MAILSTREAM *stream,long debug)
       }
 				/* get the new mailbox */
       while (!(stream = mail_open (stream,arg,debug))) {
-	prompt ("Mailbox: ",arg, sizeof(arg));
+	prompt ("Mailbox: ",arg, argmax);
 	if (!arg[0]) break;
       }
       last = 0;
@@ -323,7 +328,8 @@ void mm (MAILSTREAM *stream,long debug)
 	  break;
 	}
 	arg = cmd;
-	sprintf (arg,"%lu",last);
+	argmax = sizeof(cmd);
+	snprintf (arg, argmax, "%lu",last);
       }
       if (last > 0 && last <= stream->nmsgs)
 	mail_clearflag (stream,arg,"\\DELETED");
@@ -384,7 +390,7 @@ void overview_header (MAILSTREAM *stream
     tmp[3] = elt->answered ? 'A' : ' ';
     tmp[4] = elt->deleted ? 'D' : ' ';
     mail_parse_date (&selt,ov->date);
-    sprintf (tmp+5,"%4lu) ",elt->msgno);
+    snprintf (tmp+5, sizeof(tmp)-5, "%4lu) ",elt->msgno);
     mail_date (tmp+11,&selt);
     tmp[17] = ' ';
     tmp[18] = '\0';
@@ -394,19 +400,20 @@ void overview_header (MAILSTREAM *stream
     for (adr = ov->from; adr && !adr->host; adr = adr->next);
     if (adr) {			/* if a personal name exists use it */
       if (!(t = adr->personal))
-	sprintf (t = tmp+400,"%s@%s",adr->mailbox,adr->host);
+	snprintf (t = tmp+400, sizeof(tmp)-400, "%s@%s",adr->mailbox,adr->host);
       memcpy (tmp+18,t,(size_t) min (20,(long) strlen (t)));
     }
     strcat (tmp," ");
     if (i = elt->user_flags) {
       strcat (tmp,"{");
+      /* XXX bounds? */
       while (i) {
 	strcat (tmp,stream->user_flags[find_rightmost_bit (&i)]);
 	if (i) strcat (tmp," ");
       }
       strcat (tmp,"} ");
     }
-    sprintf (tmp + strlen (tmp),"%.25s (%lu chars)",
+    snprintf (tmp + strlen (tmp), 400 - strlen(tmp), "%.25s (%lu chars)",
 	     ov->subject ? ov->subject : " ",ov->optional.octets);
     puts (tmp);
   }
@@ -423,6 +430,7 @@ void header (MAILSTREAM *stream,long msg
   unsigned long i;
   char tmp[MAILTMPLEN];
   char *t;
+  size_t len;
   MESSAGECACHE *cache = mail_elt (stream,msgno);
   mail_fetchstructure (stream,msgno,NIL);
   tmp[0] = cache->recent ? (cache->seen ? 'R': 'N') : ' ';
@@ -430,7 +438,7 @@ void header (MAILSTREAM *stream,long msg
   tmp[2] = cache->flagged ? 'F' : ' ';
   tmp[3] = cache->answered ? 'A' : ' ';
   tmp[4] = cache->deleted ? 'D' : ' ';
-  sprintf (tmp+5,"%4lu) ",cache->msgno);
+  snprintf (tmp+5, sizeof(tmp)-5, "%4lu) ",cache->msgno);
   mail_date (tmp+11,cache);
   tmp[17] = ' ';
   tmp[18] = '\0';
@@ -445,7 +453,9 @@ void header (MAILSTREAM *stream,long msg
     strcat (tmp,"} ");
   }
   mail_fetchsubject (t = tmp + strlen (tmp),stream,msgno,(long) 25);
-  sprintf (t += strlen (t)," (%lu chars)",cache->rfc822_size);
+  len = strlen (t);
+  t += len;
+  snprintf (t, sizeof(tmp)-len, " (%lu chars)",cache->rfc822_size);
   puts (tmp);
 }
 
@@ -459,31 +469,57 @@ void display_body (BODY *body,char *pfx,
 {
   char tmp[MAILTMPLEN];
   char *s = tmp;
+  size_t len, smax = sizeof(tmp);
   PARAMETER *par;
   PART *part;			/* multipart doesn't have a row to itself */
   if (body->type == TYPEMULTIPART) {
 				/* if not first time, extend prefix */
-    if (pfx) sprintf (tmp,"%s%ld.",pfx,++i);
+    if (pfx) snprintf (tmp, sizeof(tmp), "%s%ld.",pfx,++i);
     else tmp[0] = '\0';
     for (i = 0,part = body->nested.part; part; part = part->next)
       display_body (&part->body,tmp,i++);
   }
   else {			/* non-multipart, output oneline descriptor */
     if (!pfx) pfx = "";		/* dummy prefix if top level */
-    sprintf (s," %s%ld %s",pfx,++i,body_types[body->type]);
-    if (body->subtype) sprintf (s += strlen (s),"/%s",body->subtype);
-    if (body->description) sprintf (s += strlen (s)," (%s)",body->description);
-    if (par = body->parameter) do
-      sprintf (s += strlen (s),";%s=%s",par->attribute,par->value);
+    snprintf (s, smax, " %s%ld %s",pfx,++i,body_types[body->type]);
+    if (body->subtype) {
+       len = strlen(s);
+       s += len;
+       smax -= len;
+       snprintf (s, smax, "/%s",body->subtype);
+    }
+    if (body->description) {
+       len = strlen(s);
+       s += len;
+       smax -= len;
+       snprintf (s, smax, " (%s)",body->description);
+    }
+    if (par = body->parameter) do {
+       len = strlen(s);
+       s += len;
+       smax -= len;
+       snprintf (s, smax, ";%s=%s",par->attribute,par->value);
+    }
     while (par = par->next);
-    if (body->id) sprintf (s += strlen (s),", id = %s",body->id);
+    if (body->id) {
+       len = strlen(s);
+       s += len;
+       smax -= len;
+       snprintf (s, smax, ", id = %s",body->id);
+    }
     switch (body->type) {	/* bytes or lines depending upon body type */
     case TYPEMESSAGE:		/* encapsulated message */
     case TYPETEXT:		/* plain text */
-      sprintf (s += strlen (s)," (%lu lines)",body->size.lines);
+      len = strlen(s);
+      s += len;
+      smax -= len;
+      snprintf (s, smax, " (%lu lines)",body->size.lines);
       break;
     default:
-      sprintf (s += strlen (s)," (%lu bytes)",body->size.bytes);
+      len = strlen(s);
+      s += len;
+      smax -= len;
+      snprintf (s, smax, " (%lu bytes)",body->size.bytes);
       break;
     }
     puts (tmp);			/* output this line */
@@ -492,7 +528,7 @@ void display_body (BODY *body,char *pfx,
 	(body = body->nested.msg->body)) {
       if (body->type == TYPEMULTIPART) display_body (body,pfx,i-1);
       else {			/* build encapsulation prefix */
-	sprintf (tmp,"%s%ld.",pfx,i);
+	snprintf (tmp, sizeof(tmp), "%s%ld.",pfx,i);
 	display_body (body,tmp,(long) 0);
       }
     }
@@ -711,10 +747,13 @@ void mm_login (NETMBX *mb,char *user,cha
   if (curhst) fs_give ((void **) &curhst);
   curhst = (char *) fs_get (1+strlen (mb->host));
   strcpy (curhst,mb->host);
-  sprintf (s = tmp,"{%s/%s",mb->host,mb->service);
-  if (*mb->user) sprintf (tmp+strlen (tmp),"/user=%s",strcpy (user,mb->user));
-  if (*mb->authuser) sprintf (tmp+strlen (tmp),"/authuser=%s",mb->authuser);
-  if (*mb->user) strcat (s = tmp,"} password:");
+  snprintf (s = tmp, sizeof(tmp), "{%s/%s",mb->host,mb->service);
+  if (*mb->user) snprintf (tmp+strlen (tmp), sizeof(tmp)-strlen(tmp), "/user=%s",strcpy (user,mb->user));
+  if (*mb->authuser) snprintf (tmp+strlen (tmp), sizeof(tmp)-strlen(tmp), "/authuser=%s",mb->authuser);
+  if (*mb->user) {
+     s = tmp;
+     snprintf(tmp+strlen(tmp), sizeof(tmp)-strlen(tmp), "%s", "} password:");
+  }
   else {
     printf ("%s} username: ",tmp);
     fgets (user,NETMAXUSER-1,stdin);
