#!@BUILDLINK_SHELL@
#
# $NetBSD: gen-transform.sh,v 1.1.2.2 2003/08/27 06:09:01 jlam Exp $

transform="@_BLNK_TRANSFORM_SEDFILE@"
untransform="@_BLNK_UNTRANSFORM_SEDFILE@"

# Mini-language for translating wrapper arguments into their buildlink
# equivalents:
#
#	mangle:src:dst		mangles the directory "src" into "dst"
#	rpath:src:dst		mangles the directory "src" into "dst"
#					in rpath options
#       I:src:dst		translates "-Isrc" into "-Idst"
#       L:src:dst		translates "-Lsrc" into "-Ldst"
#       l:foo:bar		translates "-lfoo" into "-lbar"
#	p:path			translates "path/*/libfoo.so" into
#					"-Lpath/* -lfoo"
#       r:dir			removes "dir" and "dir/*"
#       S:foo:bar		translates word "foo" into "bar"
#       s:foo:bar		translates "foo" into "bar"
#	static:src:dst		translates "src/libfoo.a" into "dst/libfoo.a"
#	no-rpath		removes "-R*", "-Wl,-R", and "-Wl,-rpath,*"

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
s|$2\([/ 	]\)|$3\1|g
s|$2$|$3|g
EOF
			;;
		esac
		;;
	rpath)
		gen $action mangle:-Wl,-rpath-link,$2:-Wl,-rpath-link,$3
		gen $action mangle:-Wl,-rpath,$2:-Wl,-rpath,$3
		gen $action mangle:-Wl,-R$2:-Wl,-R$3
		gen $action mangle:-R$2:-R$3
		;;
	I|L)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|-$1$2[ 	]$|-$1$3 |g
s|-$1$2$|-$1$3|g
s|-$1$2/|-$1$3/|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|-$1$3[ 	]$|-$1$2 |g
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
s|-$1$2[ 	]|-$1$3 |g
s|-$1$2$|-$1$3|g
s|-$1$2/|-$1$3/|g
EOF
			;;
		esac
		;;
	static)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|$2\(/[^ 	"':;]*/lib[^ 	/"':;]*\.a\)[ 	]|$3\1 |g
s|$2\(/[^ 	"':;]*/lib[^ 	/"':;]*\.a\)$|$3\1|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|$3\(/[^ 	"':;]*/lib[^ 	/"':;]*\.a\)[ 	]|$2\1 |g
s|$3\(/[^ 	"':;]*/lib[^ 	/"':;]*\.a\)$|$2\1|g
EOF
			;;
		esac
		;;
	p)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.so\.[0-9]*|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.so|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.so|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.[0-9]*\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.[0-9]*\.dylib|-L\1 -l\2|g
s|\($2/[^ 	"':;]*\)/lib\([^ 	/"':;]*\)\.dylib|-L\1 -l\2|g
s|\($2\)/lib\([^ 	/"':;]*\)\.dylib|-L\1 -l\2|g
EOF
			;;
		esac
		;;
	_r)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2[ 	]| |g
s|$2$||g
s|$2/[^ 	"':;]*||g
EOF
			;;
		esac
		;;
	r)
		gen $action _r:-I$2
		gen $action _r:-L$2
		gen $action _r:-Wl,-rpath-link,$2
		gen $action _r:-Wl,-rpath,$2
		gen $action _r:-Wl,-R$2
		gen $action _r:-R$2
		;;
	S)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2[ 	]|$3 |g
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
	no-rpath)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|-Wl,-rpath-link,[^ 	"':;]*||g
s|-Wl,-rpath,[^ 	"':;]*||g
s|-Wl,-R[^ 	"':;]*||g
s|-R[^ 	"':;]*||g
EOF
			;;
		esac
		;;
	esac
}

for arg do
	gen transform "$arg"
	gen untransform "$arg"
done
