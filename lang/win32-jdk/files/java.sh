#!/bin/ksh
# $NetBSD: java.sh,v 1.1.1.1 2004/10/11 13:37:10 tv Exp $
#
# Wrapper for Java under Interix.  While this is mostly useful, particularly
# if using relative pathnames, it can still fail if attempting to use
# absolute paths.  So this attempts to fixup absolute paths.
#
# That too can be a problem if options are supposed to be specified "/opt",
# but this is rare to nonexistent, so we don't currently handle that case.
#

if [ "$SYSTEMROOT" != "" ]; then
	windir="$SYSTEMROOT"
elif [ "$WINDIR" != "" ]; then
	windir="$WINDIR"
else
	echo "Cannot find %SYSTEMROOT% or %WINDIR% -- did you clear then environment?" >&2
	exit 2
fi

JAVA=$(ntpath2posix -c $windir'\system32\java.exe')

if [ ! -x $JAVA ]; then
	echo >&2
	echo "Cannot find $(posixpath2nt $JAVA) -- please install the" >&2
	echo 'Sun Java(tm) 2 Runtime Environment and/or Development Kit, available' >&2
	echo 'from:  http://www.java.com/' >&2
	echo >&2
	exit 1
fi

convert_path () {
	(IFS=:
	for dir in $1; do
		printf '%s' "$(posixpath2nt $dir);"
	done) | sed 's,;$,,'
}

do_java () {
	export CLASSPATH="$(convert_path "$CLASSPATH")"

	set -A jvmargs
	set -A args

	for arg in "$@"; do
		case "$arg" in
		/*)	arg="$(convert_path "$arg")";;
		*)	;;
		esac

		case "$arg" in
		-J*)	jvmargs[${#jvmargs}]="$(printf '%s' "$arg" | sed s,^-J,,)";;
		*)	args[${#args}]="$arg";;
		esac
	done

	exec $JAVA "${jvmargs[@]}" "${args[@]}"
}

do_jdk () {
	if [ "$JDK_HOME" = "" ]; then
		echo >&2
		echo 'Cannot find the Java 2 SDK (JDK) in C:\j2sdk*.  Please install the JDK' >&2
		echo 'in this standard location, or else set the environment variable JDK_HOME' >&2
		echo 'to the Windows pathname of the JDK.' >&2
		echo >&2
		exit 2
	fi

	posix_jdk_home="$(ntpath2posix -c "$JDK_HOME")"
	CLASSPATH="$posix_jdk_home/lib/tools.jar:$posix_jdk_home/lib/dt.jar${CLASSPATH+:$CLASSPATH}"

	do_java "$@"
}

# Find the JDK class jars, if they exist.
if [ "$JDK_HOME" = "" ]; then
	for f in $(/bin/ls -1dr /dev/fs/C/j2sdk* 2>/dev/null); do
		if [ -r $f/lib/tools.jar ]; then
			JDK_HOME=$(posixpath2nt $f)
			break
		fi
	done
fi

case $(basename $0) in
HtmlConverter)	do_jdk -jar $jdk_home/lib/htmlconverter.jar "$@";;
appletviewer)	do_jdk sun.applet.Main "$@";;
extcheck)	do_jdk com.sun.tools.extcheck.Main "$@";;
idlj)		do_jdk com.sun.tools.corba.se.idl.toJavaPortable.Compile "$@";;
jar)		do_jdk sun.tools.jar.Main "$@";;
jarsigner)	do_jdk sun.security.tools.JarSigner "$@";;
javac)		do_jdk com.sun.tools.javac.Main "$@";;
javadoc)	do_jdk com.sun.tools.javadoc.Main "$@";;
javah)		do_jdk com.sun.tools.javah.Main "$@";;
javap)		do_jdk sun.tools.javap.Main "$@";;
jdb)		do_jdk com.sun.tools.example.debug.tty.TTY "$@";;
keytool)	do_java sun.security.tools.KeyTool "$@";;
kinit)		do_java sun.security.krb5.internal.tools.Kinit "$@";;
klist)		do_java sun.security.krb5.internal.tools.Klist "$@";;
ktab)		do_java sun.security.krb5.internal.tools.Ktab "$@";;
native2ascii)	do_jdk sun.tools.native2ascii.Main "$@";;
orbd)		do_java com.sun.corba.se.internal.Activation.ORBD "$@";;
policytool)	do_java sun.security.tools.PolicyTool "$@";;
rmic)		do_jdk sun.rmi.rmic.Main "$@";;
rmid)		do_java sun.rmi.server.Activation "$@";;
rmiregistry)	do_java sun.rmi.registry.RegistryImpl "$@";;
serialver)	do_jdk sun.tools.serialver.SerialVer "$@";;
servertool)	do_java com.sun.corba.se.internal.Activation.ServerTool "$@";;
tnameserv)	do_java com.sun.corba.se.internal.CosNaming.TransientNameServer "$@";;

*)		do_java "$@";;
esac
