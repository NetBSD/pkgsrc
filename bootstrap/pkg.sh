#! /bin/sh
#
# $NetBSD: pkg.sh,v 1.1.1.1 2004/03/11 13:03:59 grant Exp $
#
#
# Copyright (c) 2002 Alistair G. Crooks.  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#	This product includes software developed by Alistair G. Crooks
#	for the NetBSD project.
# 4. The name of the author may not be used to endorse or promote
#    products derived from this software without specific prior written
#    permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
# OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#set -x

version=20020615

opsys=`uname -s`

case "$opsys" in
Darwin)
	awkprog=/usr/bin/awk
	catprog=/bin/cat
	chmodprog=/bin/chmod
	cpprog=/bin/cp
	lnprog=/bin/ln
	mkdirprog=/bin/mkdir
	rmprog=/bin/rm
	sedprog=/usr/bin/sed
	;;
Linux)
	awkprog=/usr/bin/awk
	catprog=/bin/cat
	chmodprog=/bin/chmod
	cpprog=/bin/cp
	lnprog=/bin/ln
	mkdirprog=/bin/mkdir
	rmprog=/bin/rm
	sedprog=/bin/sed
	;;
NetBSD)
	awkprog=/usr/bin/awk
	catprog=/bin/cat
	chmodprog=/bin/chmod
	cpprog=/bin/cp
	lnprog=/bin/ln
	mkdirprog=/bin/mkdir
	rmprog=/bin/rm
	sedprog=/usr/bin/sed
	;;
SunOS)
	awkprog=/usr/bin/nawk
	catprog=/usr/bin/cat
	chmodprog=/usr/bin/chmod
	cpprog=/usr/bin/cp
	lnprog=/usr/bin/ln
	mkdirprog=/usr/bin/mkdir
	rmprog=/usr/bin/rm
	sedprog=/usr/xpg4/bin/sed
	;;
*)
	awkprog=awk
	catprog=cat
	chmodprog=chmod
	cpprog=cp
	lnprog=ln
	mkdirprog=mkdir
	rmprog=rm
	sedprog=sed
	;;
esac

getpkg()
{
	if test -d $PKG_DBDIR/$1; then
		d=$PKG_DBDIR/$1
	else
		d="`echo $PKG_DBDIR/${1}-*`"
	fi
	echo $d
}

case "$DIGESTPROG" in
"")	DIGESTPROG=/usr/pkg/bin/digest ;;
esac
case "$PKG_DBDIR" in
"")     PKG_DBDIR=/var/db/pkg ;;
esac
case "$PKG_DIGEST" in
"")	PKG_DIGEST=sha1 ;;
esac

ALLDIGESTS="sha1 sha512"

case "$0" in
*pkg_create)	cmd=create ;;
*pkg_delete)	cmd=delete ;;
*pkg_info)	cmd=info ;;
*pkg.sh|*pkg)	cmd=$1; shift ;;
esac

case "$cmd" in
create)
	if [ $# -lt 1 ]; then
		echo "Usage: pkg create ..." > /dev/stderr
		exit 1
	fi

	BUILDINFOFILE=""		# done
	BUILDVERSIONFILE=""		# done
	CONFLICTS=""			# done
	comment=""			# done
	DISPLAYFILE=""			# done
	DESCRFILE=""			# done
	plist=""			# done
	minush=no
	realprefix=""
	installfile=""			# done
	deinstallfile=""		# done
	srcdir=""
	relsymlinks=no
	mtreefile=""
	plistonly=no
	PREREQS=""
	#prefix=""
	reorder=no
	requirements=""
	allsizefile=""			# done
	thissizefile=""			# done
	updatefilecache=yes
	excludefrom=""

	while [ $# -gt 0 ]; do
		case "$1" in
		-B)	BUILDINFOFILE="$2"; shift ;;
		-C)	CONFLICTS="$2"; shift ;;
		-D)	DISPLAYFILE="$2"; shift ;;
		-I)	realprefix="$2"; shift ;;
		-L)	srcdir="$2"; shift ;;
		-O)	plistonly=yes ;;
		-P)	PREREQS="$PREREQS $2"; shift ;;
		-R)	reorder=yes ;;
		-S)	allsizefile="$2"; shift ;;
		-U)	updatefilecache=no ;;
		-V)	echo $version; exit 0 ;;
		-X)	excludefrom="$excludefrom $2"; shift ;;
		-b)	BUILDVERSIONFILE="$2"; shift ;;
		-c)	case "$2" in
			-*)	comment="`echo $2 | $sedprog -e 's|^-||'`"; shift ;;
			*)	comment=`$catprog $2` ;;
			esac
			shift ;;
		-d)	DESCRFILE=$2; shift ;;
		-f)	plist="$2"; shift ;;
		-h)	minush=yes ;;
		-i)	installfile="$2"; shift ;;
		-k)	deinstallfile="$2"; shift ;;
		-l)	relsymlinks=yes ;;
		-m)	mtreefile="$2"; shift ;;
		-p)	PREFIX="$2"; shift ;;
		-r)	requirements="$2"; shift ;;
		-s)	thissizefile="$2"; shift ;;
		-t)	shift ;;
		-v)	set -x ;;
		--)	shift; break ;;
		*)	break ;;
		esac
		shift
	done

	PKGNAME=$1

	if [ ! -d $PKG_DBDIR/$PKGNAME ]; then
		$mkdirprog $PKG_DBDIR/$PKGNAME
	fi

	if [ -f "$BUILDINFOFILE" ]; then
		$cpprog $BUILDINFOFILE $PKG_DBDIR/$PKGNAME/+BUILD_INFO
	fi
	if [ -f "$BUILDVERSIONFILE" ]; then
		$cpprog $BUILDVERSIONFILE $PKG_DBDIR/$PKGNAME/+BUILD_VERSION
	fi
	echo $comment > $PKG_DBDIR/$PKGNAME/+COMMENT
	$cpprog $DESCRFILE $PKG_DBDIR/$PKGNAME/+DESC

	case "$installfile" in
	"")	;;
	*)	$cpprog $installfile $PKG_DBDIR/$PKGNAME/+INSTALL ;;
	esac
	case "$deinstallfile" in
	"")	;;
	*)	$cpprog $deinstallfile $PKG_DBDIR/$PKGNAME/+DEINSTALL ;;
	esac
	case "$DISPLAYFILE" in
	"")	;;
	*)	$cpprog $DISPLAYFILE $PKG_DBDIR/$PKGNAME/+DISPLAY ;;
	esac
	case "$allsizefile" in
	"")	;;
	*)	$cpprog $allsizefile $PKG_DBDIR/$PKGNAME/+SIZE_ALL ;;
	esac
	case "$thissizefile" in
	"")	;;
	*)	$cpprog $thissizefile $PKG_DBDIR/$PKGNAME/+SIZE_PKG ;;
	esac

	export PREFIX PKGNAME CONFLICTS PREREQS DIGESTPROG PKG_DIGEST

	$awkprog '
	BEGIN	{
		if (ENVIRON["CONFLICTS"] != "") {
			cflc = split(ENVIRON["CONFLICTS"], cflv);
			for (i = 1 ; i <= cflc ; i++)
				printf("@pkgcfl %s\n", cflv[i])
		}
		if (ENVIRON["PREREQS"] != "") {
			prec = split(ENVIRON["PREREQS"], prev);
			for (i = 1 ; i <= prec ; i++)
				printf("@pkgdep %s\n", prev[i])
		}
		prefix = ENVIRON["PREFIX"];
		printf("@name %s\n@cwd %s\n", ENVIRON["PKGNAME"], prefix) }
	/^@(comment|dirrm|src)/	{ print $0; next }
	/^@(un)?exec/	{	last = filename; gsub(".*/", "", last); gsub("%f", last);
		fc = split(filename, fv, "/"); fn = prefix; for (i = 1 ; i < fc ; i++) fn = fn "/" fv[i]; gsub("%B", fn);
		gsub("%F", filename);
		gsub("%D", prefix); print $0; next }
	{ filename = $0; printf("%s\n@comment MD5:", $0); cmd = sprintf("'$catprog' %s/%s | %s %s", prefix, $0, ENVIRON["DIGESTPROG"], ENVIRON["PKG_DIGEST"]); system(cmd) }
	' < $plist > $PKG_DBDIR/$PKGNAME/+CONTENTS

	# construct the digests of all the metafiles
	echo "#! /bin/sh" > $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo 'case $# in' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '0) ;;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '*) cd '$PKG_DBDIR/$PKGNAME ';;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo 'esac' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "$awkprog '" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo 'BEGIN	{ ex = 0 }' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo 'END	{ exit(ex) }' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '/^@cwd/	{ prefix = $2; next }' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '/^@/	{ next }' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '	{' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '	for (done = 0 ; !done ; ) {' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '		filename = prefix "/" $0;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '		getline;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '		if ($0 ~ /^@comment (MD5|SHA1):/) {' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			alg = dig = $2;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			gsub(":.*", "", alg);' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			gsub("[A-Za-z0-9]*:", "", dig);' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			cmd = sprintf("s=`'$catprog' %s | '$DIGESTPROG' %s`; if test \"%s\" != \"$s\"; then echo \"Checksum mismatch (%s): expected %s, got $s\"; fi", filename, alg, dig, filename, dig);' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			if (system(cmd) != 0) ex = 1' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '			done = 1;' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '		}' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo '	}' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "}' +CONTENTS" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "$awkprog '" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "BEGIN	{ ex = 0 }" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "END	{ exit(ex) }" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "          {" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo 'cmd = sprintf("s=`'$catprog' %s | '$DIGESTPROG' %s`; if test \"%s\" != \"$s\"; then echo \"Checksum mismatch (%s): expected %s, got $s\"; fi", $1, $2, $3, $1, $3);' >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "if (system(cmd) != 0) ex = 1" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	echo "}' << filesEOF" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	# construct the digests of all the metafiles
	for f in +BUILD_INFO +BUILD_VERSION +COMMENT +CONTENTS +DEINSTALL +DESC +DISPLAY +INSTALL +SIZE_ALL +SIZE_PKG; do
		if [ -f $PKG_DBDIR/$PKGNAME/$f ]; then
			for dig in $ALLDIGESTS; do
				echo "$f $dig `$catprog $PKG_DBDIR/$PKGNAME/$f | $DIGESTPROG $dig`" >> $PKG_DBDIR/$PKGNAME/+VERIFY
			done
		fi
	done
	echo "filesEOF" >> $PKG_DBDIR/$PKGNAME/+VERIFY
	$chmodprog 0755 $PKG_DBDIR/$PKGNAME/+VERIFY

	# change absolute symlinks to relative ones
	case "$relsymlinks" in
	yes)	for f in `$awkprog '
			$1 == "prefix"	{ prefix = $2; next }
			$1 == "file"	{ printf("%s/%s\n", prefix, $0) }
			' < $PKG_DBDIR/$PKGNAME/+INVENTORY`; do
			if [ -h $f ]; then
				target="`ls -al $1 | awk '{ print $11 }'`"
				case "$target" in
				/*)	echo $prefix $target $f | /usr/bin/awk '
						{
							pc = split($1, pv, "/");
							tc = split($2, tv, "/");
							for (i = tc - pc + 2 ; i <= tc ; i++)
								linkname = linkname "../";
							for (i = pc + 1 ; i <= tc ; i++)
								linkname = linkname "/" tv[i];
							cmd = sprintf("'$rmprog' -f %s && '$lnprog' -s %s %s", $3, linkname, $3);
							exit(system(cmd));
						}'
					;;
				esac
			fi
		done
		;;
	esac

	;;

delete)
	deinstall=yes
	force=no
	doit=yes
	justdb=no
	prefix=""
	needs=no
	reqs=no
	while [ $# -gt 0 ]; do
		case "$1" in
		-D)	deinstall=no ;;
		-O)	justdb=yes ;;
		-R)	needs=yes ;;
		-f)	force=yes ;;
		-n)	doit=no ;;
		-p)	prefix=$2; shift ;;
		-r)	reqs=yes ;;
		esac
		shift
	done
	for pkg in $@; do
		d=`getpkg $pkg`
		hitme=yes
		if [ -f $d/+REQUIRED_BY ]; then
			hitme=no
			case "$force" in
			yes)	hitme=yes ;;
			esac
			case "$needs" in
			yes)	hitme=yes ;;
			esac
			case "$hitme" in
			no)	echo "pkg_delete: package $pkg is required by other packages:"
				$catprog $d/+REQUIRED_BY
				echo "pkg_delete: 1 package deletion failed"
				continue
				;;
			esac
		fi
		case "$hitme" in
		yes)	if [ -f $d/+VERIFY ]; then
				$d/+VERIFY
			fi
			;;
		esac
		case "$reqs" in
		yes)	;;
		esac
	done
	;;

info)
	allpackages=no
	buildinfo=no
	buildversion=no
	comment=no
	display=no
	descr=no
	exist=no
	filedb=no
	plist=no
	index=no
	install=no
	deinstall=no
	entries=no
	needs=no
	prefix=no
	reqby=no
	sizeall=no
	sizepkg=no
	version=no
	if [ $# -eq 0 ]; then
		set -- -I -a
	fi
	while [ $# -gt 0 ]; do
		case "$1" in
		-B)	buildinfo=yes ;;
		-D)	display=yes ;;
		-F)	filedb=yes ;;
		-I)	index=yes ;;
		-L)	entries=yes ;;
		-S)	sizeall=yes ;;
		-V)	version=yes ;;
		-a)	allpackages=yes ;;
		-b)	buildversion=yes ;;
		-c)	comment=yes ;;
		-d)	descr=yes ;;
		-e)	exist=yes ;;
		-f)	plist=yes ;;
		-i)	install=yes ;;
		-k)	deinstall=yes ;;
		-n)	needs=yes ;;
		-p)	prefix=yes ;;
		-r)	reqby=yes ;;
		-s)	sizepkg=yes ;;
		*)	break ;;
		esac
		shift
	done
	case "$version" in
	yes)	echo $version; exit 0 ;;
	esac
	case "$filedb" in
	yes)	echo "-F is unimplemented" ;;
	esac
	case "$exist" in
	yes)	echo "-e is unimplemented" ;;
	esac
	case "$allpackages" in
	yes)	pkglist="`(cd $PKG_DBDIR; ls -d *-*)`" ;;
	*)	pkglist="$@" ;;
	esac
	for pkg in $pkglist; do
		d=`getpkg $pkg`
		case "$buildinfo" in
		yes)	$catprog $d/+BUILD_INFO ;;
		esac
		case "$display" in
		yes)	if [ -f  $d/+DISPLAY ]; then
				$catprog $d/+DISPLAY
			fi ;;
		esac
		case "$index" in
		yes)	echo "`echo $d | $sedprog -e 's|.*/||'`	`$catprog $d/+COMMENT`" ;;
		esac
		case "$entries" in
		yes)	$awkprog '
				/^@cwd/ { prefix = $2 }
				/^@/	{ next }
					{ printf("%s/%s\n", prefix, $0) }
				' < $d/+CONTENTS ;;
		esac
		case "$buildversion" in
		yes)	$catprog $d/+BUILD_VERSION ;;
		esac
		case "$comment" in
		yes)	$catprog $d/+COMMENT ;;
		esac
		case "$descr" in
		yes)	$catprog $d/+DESC ;;
		esac
		case "$install" in
		yes)	if [ -f  $d/+INSTALL ]; then
				$catprog $d/+INSTALL
			fi ;;
		esac
		case "$deinstall" in
		yes)	if [ -f  $d/+DEINSTALL ]; then
				$catprog $d/+DEINSTALL
			fi ;;
		esac
		case "$needs" in
		yes)	$awkprog '/^@pkgdep/ { print $2 }' < $d/+CONTENTS ;;
		esac
		case "$prefix" in
		yes)	$awkprog '/^@cwd/ { print $2; exit }' < $d/+CONTENTS ;;
		esac
		case "$reqby" in
		yes)	if [ -f  $d/+REQUIRED_BY ]; then
				$catprog $d/+REQUIRED_BY
			fi ;;
		esac
		case "$sizeall" in
		yes)	$catprog $d/+SIZE_ALL
		esac
		case "$sizepkg" in
		yes)	$catprog $d/+SIZE_PKG
		esac
	done
	;;

show)	
	if [ $# -lt 1 ]; then
		echo "Usage: pkg show type packages" > /dev/stderr
		exit 1
	fi

	showtype=$1
	shift
	for pkg in $@; do
		d=`getpkg $pkg`
		case "$d" in
		"")	echo "No such package ($pkg)" ;;
		*)	
			case "$showtype" in
			allsizes)
				$catprog $d/+SIZE_ALL ;;
			blddep|blddeps)
				$awkprog '/^@blddep/ { print $2 }' $d/+CONTENTS ;;
			comment)
				$catprog $d/+COMMENT ;;
			description|desc|descr)
				$catprog $d/+DESC ;;
			deinstall)
				if [ -f  $d/+DEINSTALL ]; then
					$catprog $d/+DEINSTALL
				fi ;;
			display)
				if [ -f  $d/+DISPLAY ]; then
					$catprog $d/+DISPLAY
				fi ;;
			files)
				$awkprog '
				/^@cwd/ { prefix = $2 }
				/^@/	{ next }
					{ printf("%s/%s\n", prefix, $0) }
				' < $d/+CONTENTS ;;
			index)
				echo "`echo $d | $sedprog -e 's|.*/||'`	`$catprog $d/+COMMENT`" ;;
			info)
				$catprog $d/+BUILD_INFO ;;
			install)
				if [ -f  $d/+INSTALL ]; then
					$catprog $d/+INSTALL
				fi ;;
			prefix)
				$awkprog '/^@cwd/ { print $2 }' $d/+CONTENTS ;;
			prereqs|pkgdep)
				$awkprog '/^@pkgdep/ { print $2 }' $d/+CONTENTS ;;
			size)
				$catprog $d/+SIZE_PKG ;;
			version)
				$catprog $d/+BUILD_VERSION ;;
			*)
				echo "Unknown type \"$showtype\""
				exit 1 ;;
			esac
		esac
	done
	;;

version)
	echo $version
	exit 0
	;;

*)	echo "$0: \"$cmd\" not found"
	exit 1
	;;
esac

exit 0
