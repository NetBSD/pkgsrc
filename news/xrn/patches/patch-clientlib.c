$NetBSD: patch-clientlib.c,v 1.1 2014/09/12 04:17:38 dholland Exp $

- Use standard headers.
- Silence compiler warning about braces.

--- clientlib.c~	1997-06-05 11:11:40.000000000 +0000
+++ clientlib.c
@@ -30,6 +30,7 @@ static char XRNrcsid[] = "$Id: clientlib
  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <stdlib.h>
 #include "config.h"
 #include "utils.h"
 #include <X11/Xos.h>
@@ -308,7 +309,7 @@ static int get_tcp_socket(machine)
 
 	(void) memset((char *) &sin, 0, sizeof(sin));
 
-	if (! port)
+	if (! port) {
 	  if (nntp_port)
 	    port = htons(atoi(nntp_port));
 	  else {
@@ -318,6 +319,7 @@ static int get_tcp_socket(machine)
 	    }
 	    port = sp->s_port;
 	  }
+	}
 	sin.sin_port = port;
 
 	if ((sin.sin_addr.s_addr = inet_addr(machine)) != -1) {
