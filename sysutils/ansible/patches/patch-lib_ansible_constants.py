$NetBSD: patch-lib_ansible_constants.py,v 1.4 2013/12/02 22:54:46 hubertf Exp $

--- lib/ansible/constants.py.orig	2013-11-19 19:12:32.000000000 +0000
+++ lib/ansible/constants.py
@@ -59,7 +59,7 @@ def load_config_file():
     p = ConfigParser.ConfigParser()
     path1 = os.getcwd() + "/ansible.cfg"
     path2 = os.path.expanduser(os.environ.get('ANSIBLE_CONFIG', "~/.ansible.cfg"))
-    path3 = "/etc/ansible/ansible.cfg"
+    path3 = "@PKG_SYSCONFDIR@/ansible/ansible.cfg"
 
     if os.path.exists(path1):
         p.read(path1)
@@ -88,7 +88,7 @@ if getattr(sys, "real_prefix", None):
     # in a virtualenv
     DIST_MODULE_PATH = os.path.join(sys.prefix, 'share/ansible/')
 else:
-    DIST_MODULE_PATH = '/usr/share/ansible/'
+    DIST_MODULE_PATH = '@PREFIX@/share/ansible/'
 
 # check all of these extensions when looking for yaml files for things like
 # group variables
@@ -98,7 +98,7 @@ YAML_FILENAME_EXTENSIONS = [ "", ".yml",
 DEFAULTS='defaults'
 
 # configurable things
-DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '/etc/ansible/hosts'))
+DEFAULT_HOST_LIST         = shell_expand_path(get_config(p, DEFAULTS, 'hostfile', 'ANSIBLE_HOSTS', '@PKG_SYSCONFDIR@/ansible/hosts'))
 DEFAULT_MODULE_PATH       = get_config(p, DEFAULTS, 'library',          'ANSIBLE_LIBRARY',          DIST_MODULE_PATH)
 DEFAULT_ROLES_PATH        = get_config(p, DEFAULTS, 'roles_path',       'ANSIBLE_ROLES_PATH',       None)
 DEFAULT_REMOTE_TMP        = shell_expand_path(get_config(p, DEFAULTS, 'remote_tmp',       'ANSIBLE_REMOTE_TEMP',      '$HOME/.ansible/tmp'))
@@ -128,12 +128,12 @@ DEFAULT_LEGACY_PLAYBOOK_VARIABLES = get_
 DEFAULT_JINJA2_EXTENSIONS = get_config(p, DEFAULTS, 'jinja2_extensions', 'ANSIBLE_JINJA2_EXTENSIONS', None)
 DEFAULT_EXECUTABLE        = get_config(p, DEFAULTS, 'executable', 'ANSIBLE_EXECUTABLE', '/bin/sh')
 
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
 
 ANSIBLE_NOCOLOR                = get_config(p, DEFAULTS, 'nocolor', 'ANSIBLE_NOCOLOR', None, boolean=True)
