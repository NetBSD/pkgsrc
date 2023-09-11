$NetBSD: patch-bin_pycharm.sh,v 1.3 2023/09/11 13:48:19 ryoon Exp $

Run IDE with pkgsrc choice of JVM

--- bin/pycharm.sh.orig	1970-01-20 13:32:52.000000000 +0000
+++ bin/pycharm.sh
@@ -49,6 +49,9 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # ---------------------------------------------------------------------
 JRE=""
 
+# pkgsrc choice
+PYCHARM_JDK="@PKG_JAVA_HOME@"
+
 # shellcheck disable=SC2154
 if [ -n "$PYCHARM_JDK" ] && [ -x "$PYCHARM_JDK/bin/java" ]; then
   JRE="$PYCHARM_JDK"
@@ -171,11 +174,14 @@ IFS="$(printf '\n\t')"
 # shellcheck disable=SC2086
 exec "$JAVA_BIN" \
   -classpath "$CLASS_PATH" \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   "-XX:ErrorFile=$HOME/java_error_in_pycharm_%p.log" \
   "-XX:HeapDumpPath=$HOME/java_error_in_pycharm_.hprof" \
   ${VM_OPTIONS} \
   "-Djb.vmOptionsFile=${USER_VM_OPTIONS_FILE:-${VM_OPTIONS_FILE}}" \
   ${IDE_PROPERTIES_PROPERTY} \
+  -Didea.ui.icons.svg.disk.cache=false \
   -Djava.system.class.loader=com.intellij.util.lang.PathClassLoader -Didea.vendor.name=JetBrains -Didea.paths.selector=PyCharmCE2023.2 "-Djna.boot.library.path=$IDE_HOME/lib/jna/amd64" "-Dpty4j.preferred.native.folder=$IDE_HOME/lib/pty4j" -Djna.nosys=true -Djna.noclasspath=true -Didea.platform.prefix=PyCharmCore -Dsplash=true -Daether.connector.resumeDownloads=false --add-opens=java.base/java.io=ALL-UNNAMED --add-opens=java.base/java.lang=ALL-UNNAMED --add-opens=java.base/java.lang.ref=ALL-UNNAMED --add-opens=java.base/java.lang.reflect=ALL-UNNAMED --add-opens=java.base/java.net=ALL-UNNAMED --add-opens=java.base/java.nio=ALL-UNNAMED --add-opens=java.base/java.nio.charset=ALL-UNNAMED --add-opens=java.base/java.text=ALL-UNNAMED --add-opens=java.base/java.time=ALL-UNNAMED --add-opens=java.base/java.util=ALL-UNNAMED --add-opens=java.base/java.util.concurrent=ALL-UNNAMED --add-opens=java.base/java.util.concurrent.atomic=ALL-UNNAMED --add-opens=java.base/jdk.internal.vm=ALL-UNNAMED --add-opens=java.base/sun.nio.ch=ALL-UNNAMED --add-opens=java.base/sun.nio.fs=ALL-UNNAMED --add-opens=java.base/sun.security.ssl=ALL-UNNAMED --add-opens=java.base/sun.security.util=ALL-UNNAMED --add-opens=java.base/sun.net.dns=ALL-UNNAMED --add-opens=java.desktop/com.sun.java.swing.plaf.gtk=ALL-UNNAMED --add-opens=java.desktop/java.awt=ALL-UNNAMED --add-opens=java.desktop/java.awt.dnd.peer=ALL-UNNAMED --add-opens=java.desktop/java.awt.event=ALL-UNNAMED --add-opens=java.desktop/java.awt.image=ALL-UNNAMED --add-opens=java.desktop/java.awt.peer=ALL-UNNAMED --add-opens=java.desktop/java.awt.font=ALL-UNNAMED --add-opens=java.desktop/javax.swing=ALL-UNNAMED --add-opens=java.desktop/javax.swing.plaf.basic=ALL-UNNAMED --add-opens=java.desktop/javax.swing.text.html=ALL-UNNAMED --add-opens=java.desktop/sun.awt.X11=ALL-UNNAMED --add-opens=java.desktop/sun.awt.datatransfer=ALL-UNNAMED --add-opens=java.desktop/sun.awt.image=ALL-UNNAMED --add-opens=java.desktop/sun.awt=ALL-UNNAMED --add-opens=java.desktop/sun.font=ALL-UNNAMED --add-opens=java.desktop/sun.java2d=ALL-UNNAMED --add-opens=java.desktop/sun.swing=ALL-UNNAMED --add-opens=java.desktop/com.sun.java.swing=ALL-UNNAMED --add-opens=jdk.attach/sun.tools.attach=ALL-UNNAMED --add-opens=jdk.compiler/com.sun.tools.javac.api=ALL-UNNAMED --add-opens=jdk.internal.jvmstat/sun.jvmstat.monitor=ALL-UNNAMED --add-opens=jdk.jdi/com.sun.tools.jdi=ALL-UNNAMED \
   com.intellij.idea.Main \
   "$@"
