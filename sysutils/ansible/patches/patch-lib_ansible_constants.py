$NetBSD: patch-lib_ansible_constants.py,v 1.3 2013/04/13 17:51:57 riz Exp $

--- lib/ansible/constants.py.orig	2013-03-04 13:18:12.000000000 -0800
+++ lib/ansible/constants.py	2013-04-13 09:48:31.000000000 -0700
@@ -36,7 +36,7 @@
     p = ConfigParser.ConfigParser()
     path1 = os.path.expanduser(os.environ.get('ANSIBLE_CONFIG', "~/.ansible.cfg"))
     path2 = os.getcwd() + "/ansible.cfg"
-    path3 = "/etc/ansible/ansible.cfg"
+    path3 = "@PKG_SYSCONFDIR@/ansible/ansible.cfg"
 
     if os.path.exists(path1):
         p.read(path1)
@@ -64,13 +64,13 @@
 if getattr(sys, "real_prefix", None):
     DIST_MODULE_PATH = os.path.join(sys.prefix, 'share/ansible/')
 else:
-    DIST_MODULE_PATH = '/usr/share/ansible/'
+    DIST_MODULE_PATH = '@PREFIX@/share/ansible/'			
 
 # sections in config file
 DEFAULTS='defaults'
 
 # configurable things
-DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile',         'ANSIBLE_HOSTS',            '/etc/ansible/hosts'))
+DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile',         'ANSIBLE_HOSTS',            '@PKG_SYSCONFDIR@/ansible/hosts'))
 DEFAULT_MODULE_PATH       = shell_expand_path(get_config(p, DEFAULTS, 'library',          'ANSIBLE_LIBRARY',          DIST_MODULE_PATH))
 DEFAULT_REMOTE_TMP        = shell_expand_path(get_config(p, DEFAULTS, 'remote_tmp',       'ANSIBLE_REMOTE_TEMP',      '$HOME/.ansible/tmp'))
 DEFAULT_MODULE_NAME       = get_config(p, DEFAULTS, 'module_name',      None,                       'command')
@@ -96,12 +96,12 @@
 DEFAULT_HASH_BEHAVIOUR    = get_config(p, DEFAULTS, 'hash_behaviour', 'ANSIBLE_HASH_BEHAVIOUR', 'replace')
 DEFAULT_JINJA2_EXTENSIONS = get_config(p, DEFAULTS, 'jinja2_extensions', 'ANSIBLE_JINJA2_EXTENSIONS', None)
 
-DEFAULT_ACTION_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '/usr/share/ansible_plugins/action_plugins'))
-DEFAULT_CALLBACK_PLUGIN_PATH   = shell_expand_path(get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '/usr/share/ansible_plugins/callback_plugins'))
-DEFAULT_CONNECTION_PLUGIN_PATH = shell_expand_path(get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '/usr/share/ansible_plugins/connection_plugins'))
-DEFAULT_LOOKUP_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '/usr/share/ansible_plugins/lookup_plugins'))
-DEFAULT_VARS_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'vars_plugins',     'ANSIBLE_VARS_PLUGINS', '/usr/share/ansible_plugins/vars_plugins'))
-DEFAULT_FILTER_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '/usr/share/ansible_plugins/filter_plugins'))
+DEFAULT_ACTION_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '@PREFIX@/share/ansible_plugins/action_plugins'))
+DEFAULT_CALLBACK_PLUGIN_PATH   = shell_expand_path(get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '@PREFIX@/share/ansible_plugins/callback_plugins'))
+DEFAULT_CONNECTION_PLUGIN_PATH = shell_expand_path(get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '@PREFIX@/share/ansible_plugins/connection_plugins'))
+DEFAULT_LOOKUP_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '@PREFIX@/share/ansible_plugins/lookup_plugins'))
+DEFAULT_VARS_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'vars_plugins',     'ANSIBLE_VARS_PLUGINS', '@PREFIX@/share/ansible_plugins/vars_plugins'))
+DEFAULT_FILTER_PLUGIN_PATH     = shell_expand_path(get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '@PREFIX@/share/ansible_plugins/filter_plugins'))
 
 # non-configurable things
 DEFAULT_SUDO_PASS         = None
