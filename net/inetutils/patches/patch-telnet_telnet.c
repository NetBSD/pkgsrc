$NetBSD: patch-telnet_telnet.c,v 1.1 2018/12/13 05:34:38 maya Exp $

Avoid easy buffer overflow.

--- telnet/telnet.c.orig	2015-03-31 15:40:50.000000000 +0000
+++ telnet/telnet.c
@@ -861,7 +861,7 @@ suboption (void)
 	  len = strlen (name) + 4 + 2;
 	  if (len < NETROOM ())
 	    {
-	      sprintf ((char *) temp, "%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
+	      snprintf ((char *) temp, sizeof(temp), "%c%c%c%c%s%c%c", IAC, SB, TELOPT_TTYPE,
 		       TELQUAL_IS, name, IAC, SE);
 	      ring_supply_data (&netoring, temp, len);
 	      printsub ('>', &temp[2], len - 2);
@@ -885,7 +885,7 @@ suboption (void)
 
 	  TerminalSpeeds (&ispeed, &ospeed);
 
-	  sprintf ((char *) temp, "%c%c%c%c%d,%d%c%c", IAC, SB, TELOPT_TSPEED,
+	  snprintf ((char *) temp, sizeof(temp), "%c%c%c%c%d,%d%c%c", IAC, SB, TELOPT_TSPEED,
 		   TELQUAL_IS, (int) ospeed, (int) ispeed, IAC, SE);
 	  len = strlen ((char *) temp + 4) + 4;	/* temp[3] is 0 ... */
 
@@ -999,7 +999,7 @@ suboption (void)
 	      send_wont (TELOPT_XDISPLOC, 1);
 	      break;
 	    }
-	  sprintf ((char *) temp, "%c%c%c%c%s%c%c", IAC, SB, TELOPT_XDISPLOC,
+	  snprintf ((char *) temp, sizeof(temp), "%c%c%c%c%s%c%c", IAC, SB, TELOPT_XDISPLOC,
 		   TELQUAL_IS, dp, IAC, SE);
 	  len = strlen ((char *) temp + 4) + 4;	/* temp[3] is 0 ... */
 
