$NetBSD: patch-msgbind.c,v 1.1 2015/05/10 18:50:47 bsiegert Exp $

Fix overlap string copy

--- msgbind.c.orig     2015-04-25 16:26:29.000000000 +0000
+++ msgbind.c
@@ -578,7 +578,7 @@ int main(int argc, char **argv)
    }
    strcat(pool[tpool].data, msgname);
    strcat(pool[tpool].data, ", ");
-   strcpy(msg_buffer, msg_buffer+1);
+   memmove(msg_buffer, msg_buffer+1, strlen(msg_buffer));
    buf_len=strlen(msg_buffer);
    msg_buffer[--buf_len]='\0';
    patch_string(msg_buffer);
