#!@BUILDLINK_SHELL@
#
# $NetBSD: gen-transform.sh,v 1.1.2.8 2003/08/30 10:02:34 jlam Exp $

transform="@_BLNK_TRANSFORM_SEDFILE@"
untransform="@_BLNK_UNTRANSFORM_SEDFILE@"

# Mini-language for translating wrapper arguments into their buildlink
# equivalents:
#
#	mangle:src:dst		mangles the directory "src" into "dst"
#	rpath:src:dst		translates the directory "src" into "dst"
#					in rpath options
#	no-rpath		removes "-R*", "-Wl,-R", and "-Wl,-rpath,*"
#	depot:src:dst		translates "src/<dir>/" into "dst/"
#	I:src:dst		translates "-Isrc" into "-Idst"
#	L:src:dst		translates "-Lsrc" into "-Ldst"
#	l:foo:bar		translates "-lfoo" into "-lbar"
#	P:src:dst		translates "src/libfoo.{a,la}" into
#					"dst/libfoo.{a,la}"
#	p:path			translates "path/*/libfoo.so" into
#					"-Lpath/* -lfoo"
#	r:dir			removes "dir" and "dir/*"
#	S:foo:bar		translates word "foo" into "bar"
#	s:foo:bar		translates "foo" into "bar"
#
# Some transformations only make sense in one direction, so if a command
# is prefixed with either "transform:" or "untransform:", then the
# resulting sed commands are only appended the the corresponding sedfile.

gen() {
	action=$1; shift
	case "$action" in
	transform)	sedfile="$transform"   ;;
	untransform)	sedfile="$untransform" ;;
	esac
	save_IFS="${IFS}"; IFS=":"
	set -- $1
	IFS="${save_IFS}"
	case "$1" in
	mangle)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2\([/ 	\`"':;]\)|$3\1|g
s|$2$|$3|g
EOF
			;;
		esac
		;;
	rpath)
		gen $action mangle:-Wl,--rpath-link,$2:-Wl,--rpath-link,$3
		gen $action mangle:-Wl,--rpath,$2:-Wl,--rpath,$3
		gen $action mangle:-Wl,-rpath-link,$2:-Wl,-rpath-link,$3
		gen $action mangle:-Wl,-rpath,$2:-Wl,-rpath,$3
		gen $action mangle:-Wl,-R$2:-Wl,-R$3
		gen $action mangle:-R$2:-R$3
		;;
	no-rpath)
		gen $action _r:-Wl,--rpath-link,
		gen $action _r:-Wl,--rpath,
		gen $action _r:-Wl,-rpath-link,
		gen $action _r:-Wl,-rpath,
		gen $action _r:-Wl,-R
		gen $action _r:-R
		;;
	depot)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2/[^/ 	\`"':;]*\(/[^ 	\`"':;]\)|$3\1|g
s|$2/[^/ 	\`"':;]*$|$3|g
EOF
			;;
		esac
		;;
	I|L)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|-$1$2\([ 	\`"':;]\)$|-$1$3\1|g
s|-$1$2$|-$1$3|g
s|-$1$2/|-$1$3/|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|-$1$3\([ 	\`"':;]\)$|-$1$2\1|g
s|-$1$3$|-$1$2|g
s|-$1$3/|-$1$2/|g
EOF
			;;
		esac
		;;
	l)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|-$1$2\([ 	"';;]\)|-$1$3\1|g
s|-$1$2$|-$1$3|g
s|-$1$2/|-$1$3/|g
EOF
			;;
		esac
		;;
	P)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|$2\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.la\)\([ 	\`"':;]\)|$3\1\2|g
s|$2\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.la\)$|$3\1|g
s|$2\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.a\)\([ 	\`"':;]\)|$3\1\2|g
s|$2\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.a\)$|$3\1|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|$3\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.a\)\([ 	\`"':;]\)|$2\1\2|g
s|$3\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.a\)$|$2\1|g
s|$3\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.la\)\([ 	\`"':;]\)|$2\1\2|g
s|$3\(/[^ 	\`"':;]*/lib[^/ 	\`"':;]*\.la\)$|$2\1|g
EOF
			;;
		esac
		;;
	p)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.so\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.so|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.so|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2/[^ 	\`"':;]*\)/lib\([^/ 	\`"':;]*\)\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^/ 	\`"':;]*\)\.dylib|-L\1 -l\2|g
EOF
			;;
		esac
		;;
	__r)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2/[^ 	\`"':;]*||g
EOF
			;;
		esac
		;;
	_r)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2\([ 	\`"':;]\)|\1|g
s|$2$||g
s|$2/[^ 	\`"':;]*||g
EOF
			;;
		esac
		;;
	r)
		case "$2" in
		"")	r=__r ;;
		*)	r=_r ;;
		esac
		gen $action $r:-I$2
		gen $action $r:-L$2
		gen $action $r:-Wl,--rpath-link,$2
		gen $action $r:-Wl,--rpath,$2
		gen $action $r:-Wl,-rpath-link,$2
		gen $action $r:-Wl,-rpath,$2
		gen $action $r:-Wl,-R$2
		gen $action $r:-R$2
		;;
	S)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2\([ 	\`"':;]\)|$3\1|g
s|$2$|$3|g
EOF
			;;
		esac
		;;
	s)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2|$3|g
EOF
			;;
		esac
		;;
	*)
		echo "Unknown arg: $arg" 1>&2
		exit 1
		;;
	esac
}

for arg; do
	case $arg in
	transform:*)
		gen transform "${arg#transform:}"
		;;
	untransform:*)
		gen untransform "${arg#untransform:}"
		;;
	*)
		gen transform "$arg"
		gen untransform "$arg"
		;;
	esac
done
