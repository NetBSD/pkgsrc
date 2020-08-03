$NetBSD: patch-Build.sh,v 1.1 2020/08/03 15:13:55 tnn Exp $

remove double brackets

--- Build.sh.orig	2020-08-03 15:12:31.960450602 +0000
+++ Build.sh
@@ -2520,7 +2520,7 @@ cat >test.sh <<-EOF
 	for y in "\${check_categories[@]}"; do
 		x=\$x,\$y
 	done
-	if [[ -n \$x ]]; then
+	if [ -n \$x ]; then
 		args[\${#args[*]}]=-C
 		args[\${#args[*]}]=\${x#,}
 	fi
@@ -2539,7 +2539,7 @@ cat >test.sh <<-EOF
 	fi
 	(( vflag )) && args[\${#args[*]}]=-v
 	(( xflag )) && args[\${#args[*]}]=-x	# force usage by synerr
-	if [[ -n \$TMPDIR && -d \$TMPDIR/. ]]; then
+	if [ -n \$TMPDIR && -d \$TMPDIR/. ]; then
 		args[\${#args[*]}]=-T
 		args[\${#args[*]}]=\$TMPDIR
 	fi
@@ -2550,7 +2550,7 @@ cat >test.sh <<-EOF
 	cstr='\$os = defined \$^O ? \$^O : "unknown";'
 	cstr="\$cstr"'print \$os . ", Perl version " . \$];'
 	for perli in \$PERL perl5 perl no; do
-		if [[ \$perli = no ]]; then
+		if [ \$perli = no ]; then
 			print Cannot find a working Perl interpreter, aborting.
 			exit 1
 		fi
@@ -2562,7 +2562,7 @@ cat >test.sh <<-EOF
 			print "=> not using"
 			continue
 		fi
-		if [[ -n \$perlos ]]; then
+		if [ -n \$perlos ]; then
 			print "=> using it"
 			break
 		fi
