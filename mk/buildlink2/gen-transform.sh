#!@BUILDLINK_SHELL@

transform="@_BLNK_TRANSFORM_SEDFILE@"
untransform="@_BLNK_UNTRANSFORM_SEDFILE@"

# Mini-language for translating wrapper arguments into their buildlink
# equivalents:
#
#       I:src:dst		translates "-Isrc" into "-Idst"
#       II:src:dst1:dst2	translates "-Isrc" into "-Idst1 -Idst2"
#       L:src:dst		translates "-Lsrc" into "-Ldst"
#       LL:src:dst1:dst2	translates "-Lsrc" into "-Ldst1 -Ldst2"
#       l:foo:bar		translates "-lfoo" into "-lbar"
#	p:path			translates "/usr/pkg/lib/libfoo.{a,so}" into
#					"-L/usr/pkg/lib -lfoo"
#       r:dir			removes "dir" and "dir/*"
#       S:foo:bar		translates word "foo" into "bar"
#       s:foo:bar		translates "foo" into "bar"

gen() {
	action=$1; shift
	case "$action" in
	transform)	sedfile="$transform"   ;;
	untransform)	sedfile="$untransform" ;;
	esac
	save_IFS="${IFS}"; IFS=":"
	set -- $1
	case "$1" in
	I|L)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|-$1$2[ 	]$|-$1$3 |g
s|-$1$2$|-$1$3|g
s|-$1$2\([^ 	]*\)|-$1$3\1|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|-$1$3[ 	]$|-$1$2 |g
s|-$1$3$|-$1$2|g
s|-$1$3\([^ 	].*\)|-$1$2\1|g
EOF
			;;
		esac
		;;
	II|LL)
		case "$1" in II) opt=I ;; LL) opt=L ;; esac
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|-$opt$2[ 	]$|-$opt$3 -$opt$4 |g
s|-$opt$2$|-$opt$3 -$opt$4|g
s|-$opt$2\([^ 	]*\)|-$opt$3\1 -$opt$4\1|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|-$opt$3[ 	]$|-$opt$2 |g
s|-$opt$4$|-$opt$2|g
s|-$opt$4\([^ 	]*\)|-$opt$2\1|g
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
EOF
			;;
		esac
		;;
	p)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|\($2/[^ 	]*\)/lib\([^ 	/]*\)\.a|-L\1 -l\2|g
s|\($2/[^ 	]*\)/lib\([^ 	/]*\)\.so|-L\1 -l\2|g
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
s|$2[^ 	]*||g
EOF
			;;
		esac
		;;
	r)
		gen $action _r:-I$2
		gen $action _r:-L$2
		gen $action _r:-Wl,-R$2
		gen $action _r:-Wl,-rpath,$2
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
s|-Wl,-R[^ 	]*||g
s|-Wl,-rpath,[^ 	]*||g
s|-R[^ 	]*||g
EOF
			;;
		esac
		;;
	esac
	IFS="${save_IFS}"
}

for arg; do
	gen transform "$arg"
	gen untransform "$arg"
done
