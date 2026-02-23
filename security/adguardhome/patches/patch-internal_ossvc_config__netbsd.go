$NetBSD: patch-internal_ossvc_config__netbsd.go,v 1.1 2026/02/23 13:22:15 adam Exp $

Compile in contents of files/adguardhome.sh.

--- /dev/null	2026-02-23 12:20:15.725096000 +0000
+++ internal/ossvc/config_netbsd.go
@@ -0,0 +1,31 @@
+//go:build netbsd
+
+package ossvc
+
+import (
+	"github.com/kardianos/service"
+)
+
+// configureServiceOptions defines additional settings of the service
+// configuration on FreeBSD.  conf must not be nil.
+func configureOSOptions(conf *service.Config) {
+	conf.Option["SysvScript"] = netBSDScript
+}
+
+//lint:ignore U1000 TODO(e.burkov): Use.
+const netBSDScript = `#!@RCD_SCRIPTS_SHELL@
+# PROVIDE: adguardhome
+# REQUIRE: DAEMON
+# BEFORE:  LOGIN
+
+. /etc/rc.subr
+
+name="AdGuardHome"
+rcvar="adguardhome"
+command="@PREFIX@/bin/${name}"
+command_args="--no-check-update -c @PKG_SYSCONFDIR@/AdGuardHome.yaml -w @PREFIX@/libdata/adguardhome --pidfile @VARBASE@/run/${name}.pid -l syslog &"
+pidfile="/var/run/${name}.pid"
+
+load_rc_config $name
+run_rc_command "$1"
+`
