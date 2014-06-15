$NetBSD: patch-lib_ansible_constants.py,v 1.5 2014/06/15 00:15:08 rodent Exp $

Fix hardcoded paths to be replaced with SUBST framework.

--- lib/ansible/constants.py.orig	2014-06-09 21:23:31.000000000 +0000
+++ lib/ansible/constants.py
@@ -65,7 +65,7 @@ def load_config_file():
         path0 = os.path.expanduser(path0)
     path1 = os.getcwd() + "/ansible.cfg"
     path2 = os.path.expanduser("~/.ansible.cfg")
-    path3 = "/etc/ansible/ansible.cfg"
+    path3 = "@PKG_SYSCONFDIR@/ansible/ansible.cfg"
 
     for path in [path0, path1, path2, path3]:
         if path is not None and os.path.exists(path):
@@ -90,7 +90,7 @@ if getattr(sys, "real_prefix", None):
     # in a virtualenv
     DIST_MODULE_PATH = os.path.join(sys.prefix, 'share/ansible/')
 else:
-    DIST_MODULE_PATH = '/usr/share/ansible/'
+    DIST_MODULE_PATH = '@PREFIX@/share/ansible/'
 
 # check all of these extensions when looking for yaml files for things like
 # group variables -- really anything we can load
@@ -100,7 +100,7 @@ YAML_FILENAME_EXTENSIONS = [ "", ".yml",
 DEFAULTS='defaults'
 
 # configurable things
-DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '/etc/ansible/hosts'))
+DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '@PKG_SYSCONFDIR@/ansible/hosts'))
 DEFAULT_MODULE_PATH       = get_config(p, DEFAULTS, 'library',          'ANSIBLE_LIBRARY',          DIST_MODULE_PATH)
 DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       '/etc/ansible/roles')
 DEFAULT_REMOTE_TMP        = shell_expand_path(get_config(p, DEFAULTS, 'remote_tmp',       'ANSIBLE_REMOTE_TEMP',      '$HOME/.ansible/tmp'))
@@ -136,12 +136,12 @@ DEFAULT_SU_USER = get_config(p, DEFAULTS
 DEFAULT_ASK_SU_PASS = get_config(p, DEFAULTS, 'ask_su_pass', 'ANSIBLE_ASK_SU_PASS', False, boolean=True)
 DEFAULT_GATHERING = get_config(p, DEFAULTS, 'gathering', 'ANSIBLE_GATHERING', 'implicit').lower()
 
-DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '/usr/share/ansible_plugins/action_plugins')
-DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '/usr/share/ansible_plugins/callback_plugins')
-DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '/usr/share/ansible_plugins/connection_plugins')
-DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '/usr/share/ansible_plugins/lookup_plugins')
-DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '/usr/share/ansible_plugins/vars_plugins')
-DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '/usr/share/ansible_plugins/filter_plugins')
+DEFAULT_ACTION_PLUGIN_PATH     = get_config(p, DEFAULTS, 'action_plugins',     'ANSIBLE_ACTION_PLUGINS', '@PREFIX@/share/ansible_plugins/action_plugins')
+DEFAULT_CALLBACK_PLUGIN_PATH   = get_config(p, DEFAULTS, 'callback_plugins',   'ANSIBLE_CALLBACK_PLUGINS', '@PREFIX@/share/ansible_plugins/callback_plugins')
+DEFAULT_CONNECTION_PLUGIN_PATH = get_config(p, DEFAULTS, 'connection_plugins', 'ANSIBLE_CONNECTION_PLUGINS', '@PREFIX@/share/ansible_plugins/connection_plugins')
+DEFAULT_LOOKUP_PLUGIN_PATH     = get_config(p, DEFAULTS, 'lookup_plugins',     'ANSIBLE_LOOKUP_PLUGINS', '@PREFIX@/share/ansible_plugins/lookup_plugins')
+DEFAULT_VARS_PLUGIN_PATH       = get_config(p, DEFAULTS, 'vars_plugins',       'ANSIBLE_VARS_PLUGINS', '@PREFIX@/share/ansible_plugins/vars_plugins')
+DEFAULT_FILTER_PLUGIN_PATH     = get_config(p, DEFAULTS, 'filter_plugins',     'ANSIBLE_FILTER_PLUGINS', '@PREFIX@/share/ansible_plugins/filter_plugins')
 DEFAULT_LOG_PATH               = shell_expand_path(get_config(p, DEFAULTS, 'log_path',           'ANSIBLE_LOG_PATH', ''))
 
 ANSIBLE_FORCE_COLOR            = get_config(p, DEFAULTS, 'force_color', 'ANSIBLE_FORCE_COLOR', None, boolean=True)
