$NetBSD: patch-bin_idea.sh,v 1.4 2025/08/15 15:54:27 schmonz Exp $

Add a few JVM options to make it work in a common case.

-Didea.ui.icons.svg.disk.cache=false part is obtained
from: https://youtrack.jetbrains.com/issue/IDEA-323750 .

--- bin/idea.sh.orig	1970-01-21 07:13:44.000000000 +0000
+++ bin/idea.sh
@@ -49,6 +49,7 @@ CONFIG_HOME="${XDG_CONFIG_HOME:-${HOME}/
 # ---------------------------------------------------------------------
 JRE=""
 
+IDEA_JDK=@PKG_JAVA_HOME@
 # shellcheck disable=SC2154
 if [ -n "$IDEA_JDK" ] && [ -x "$IDEA_JDK/bin/java" ]; then
   JRE="$IDEA_JDK"
@@ -186,12 +187,16 @@ CLASS_PATH="$CLASS_PATH:$IDE_HOME/lib/ut
 IFS="$(printf '\n\t')"
 # shellcheck disable=SC2086
 exec "$JAVA_BIN" \
+  -Xmx4096 -Xms4096 \
+  -XX:-UseCompressedClassPointers \
+  -XX:-UseCompressedOops \
   -classpath "$CLASS_PATH" \
   "-XX:ErrorFile=$HOME/java_error_in_idea_%p.log" \
   "-XX:HeapDumpPath=$HOME/java_error_in_idea_.hprof" \
   ${VM_OPTIONS} \
   "-Djb.vmOptionsFile=${USER_VM_OPTIONS_FILE:-${VM_OPTIONS_FILE}}" \
   ${IDE_PROPERTIES_PROPERTY} \
+  -Didea.ui.icons.svg.disk.cache=false \
   "-Xbootclasspath/a:$IDE_HOME/lib/nio-fs.jar" -Djava.system.class.loader=com.intellij.util.lang.PathClassLoader -Didea.vendor.name=JetBrains -Didea.paths.selector=IdeaIC2025.2 "-Djna.boot.library.path=$IDE_HOME/lib/jna/amd64" -Djna.nosys=true -Djna.noclasspath=true "-Dpty4j.preferred.native.folder=$IDE_HOME/lib/pty4j" -Dio.netty.allocator.type=pooled "-Dintellij.platform.runtime.repository.path=$IDE_HOME/modules/module-descriptors.dat" -Didea.platform.prefix=Idea -Dsplash=true -Daether.connector.resumeDownloads=false -Dcompose.swing.render.on.graphics=true --add-opens=java.base/java.io=ALL-UNNAMED --add-opens=java.base/java.lang=ALL-UNNAMED --add-opens=java.base/java.lang.ref=ALL-UNNAMED --add-opens=java.base/java.lang.reflect=ALL-UNNAMED --add-opens=java.base/java.net=ALL-UNNAMED --add-opens=java.base/java.nio=ALL-UNNAMED --add-opens=java.base/java.nio.charset=ALL-UNNAMED --add-opens=java.base/java.text=ALL-UNNAMED --add-opens=java.base/java.time=ALL-UNNAMED --add-opens=java.base/java.util=ALL-UNNAMED --add-opens=java.base/java.util.concurrent=ALL-UNNAMED --add-opens=java.base/java.util.concurrent.atomic=ALL-UNNAMED --add-opens=java.base/java.util.concurrent.locks=ALL-UNNAMED --add-opens=java.base/jdk.internal.vm=ALL-UNNAMED --add-opens=java.base/sun.net.dns=ALL-UNNAMED --add-opens=java.base/sun.nio.ch=ALL-UNNAMED --add-opens=java.base/sun.nio.fs=ALL-UNNAMED --add-opens=java.base/sun.security.ssl=ALL-UNNAMED --add-opens=java.base/sun.security.util=ALL-UNNAMED --add-opens=java.desktop/com.sun.java.swing=ALL-UNNAMED --add-opens=java.desktop/com.sun.java.swing.plaf.gtk=ALL-UNNAMED --add-opens=java.desktop/java.awt=ALL-UNNAMED --add-opens=java.desktop/java.awt.dnd.peer=ALL-UNNAMED --add-opens=java.desktop/java.awt.event=ALL-UNNAMED --add-opens=java.desktop/java.awt.font=ALL-UNNAMED --add-opens=java.desktop/java.awt.image=ALL-UNNAMED --add-opens=java.desktop/java.awt.peer=ALL-UNNAMED --add-opens=java.desktop/javax.swing=ALL-UNNAMED --add-opens=java.desktop/javax.swing.plaf.basic=ALL-UNNAMED --add-opens=java.desktop/javax.swing.text=ALL-UNNAMED --add-opens=java.desktop/javax.swing.text.html=ALL-UNNAMED --add-opens=java.desktop/javax.swing.text.html.parser=ALL-UNNAMED --add-opens=java.desktop/sun.awt=ALL-UNNAMED --add-opens=java.desktop/sun.awt.X11=ALL-UNNAMED --add-opens=java.desktop/sun.awt.datatransfer=ALL-UNNAMED --add-opens=java.desktop/sun.awt.image=ALL-UNNAMED --add-opens=java.desktop/sun.font=ALL-UNNAMED --add-opens=java.desktop/sun.java2d=ALL-UNNAMED --add-opens=java.desktop/sun.swing=ALL-UNNAMED --add-opens=java.management/sun.management=ALL-UNNAMED --add-opens=jdk.attach/sun.tools.attach=ALL-UNNAMED --add-opens=jdk.compiler/com.sun.tools.javac.api=ALL-UNNAMED --add-opens=jdk.internal.jvmstat/sun.jvmstat.monitor=ALL-UNNAMED --add-opens=jdk.jdi/com.sun.tools.jdi=ALL-UNNAMED \
   com.intellij.idea.Main \
   "$@"
