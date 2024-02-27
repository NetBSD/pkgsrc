$NetBSD: patch-python_vmailmgr_commands.py,v 1.1 2024/02/27 19:13:44 schmonz Exp $

Port to Python 3, maintaining 2.7 compatibility.

--- python/vmailmgr/commands.py.orig	2015-09-01 16:03:21.000000000 +0000
+++ python/vmailmgr/commands.py
@@ -14,45 +14,44 @@
 # along with this program; if not, write to the Free Software
 # Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
-import daemon
-import string
-import types
+import vmailmgr.daemon
+import vmailmgr.types
 
 def execute(command, *args):
-    return daemon.execute(command, args)
+    return vmailmgr.daemon.execute(command, args)
 
 def check(domain, username, password):
     return execute('check', domain, username, password)
 
 def listdomain(domain, password):
-    conn = daemon.Daemon()
-    response = conn.execute(daemon.Command('listdomain', (domain, password)))
+    conn = vmailmgr.daemon.Daemon()
+    response = conn.execute(vmailmgr.daemon.Command('listdomain', (domain, password)))
     users = []
     while 1:
         r = conn.read_response()
         if not r:
             break
-        (username,data) = string.split(r, '\0', 1)
-        users.append(types.NamedVUser(username, types.VUser(data)))
+        (username,data) = r.split('\0', 1)
+        users.append(vmailmgr.types.NamedVUser(username, vmailmgr.types.VUser(data)))
     return users
 
 def adduser(domain, newuser, password, newpass,
             maildir=None, has_mailbox=None, forwards=[]):
-    return daemon.execute('adduser3',
+    return vmailmgr.daemon.execute('adduser3',
                           (domain, newuser, password, newpass,
                            maildir or '', has_mailbox or '') + tuple(forwards))
 
 def lookup(domain, username, password):
-    return types.VUser(execute('lookup', domain, username, password))
+    return vmailmgr.types.VUser(execute('lookup', domain, username, password))
 
 def autoresponse(domain, user, password, action, message=None):
     cmd = [ domain, user, password, action ]
     if message:
         cmd.append(message)
-    return daemon.execute('autoresponse', cmd)
+    return vmailmgr.daemon.execute('autoresponse', cmd)
 
 def deluser(domain, username, password):
     return execute('deluser', domain, username, password)
 
 def chattr(domain, username, password, attribute, *value):
-    return daemon.execute('chattr', (domain,username,password,attribute)+value)
+    return vmailmgr.daemon.execute('chattr', (domain,username,password,attribute)+value)
