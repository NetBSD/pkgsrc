#!@BUILDLINK_SHELL@
#
# $NetBSD: gen-transform.sh,v 1.27 2004/06/04 19:21:23 tv Exp $

transform="@_BLNK_TRANSFORM_SEDFILE@"
untransform="@_BLNK_UNTRANSFORM_SEDFILE@"
reorderlibs="@_BLNK_REORDERLIBS@"

# Mini-language for translating wrapper arguments into their buildlink
# equivalents:
#
#	mangle:src:dst		mangles the directory "src" into "dst"
#	sub-mangle:src:dst	mangles "src/*" into "dst/*"
#	rpath:src:dst		translates the directory "src" into "dst"
#					in rpath options
#	sub-rpath:src:dst	translates "src/*" into "dst/*" in rpath
#					options
#	abs-rpath		removes all rpath options that try to add
#					relative paths
#	no-rpath		removes "-R*", "-Wl,-R", and "-Wl,-rpath,*"
#	reorder:l:foo:bar	reorders libs to ensure that "-lfoo"
#				occurs before "-lbar"
#	depot:src:dst		translates "src/<dir>/" into "dst/"
#	I:src:dst		translates "-Isrc" into "-Idst"
#	L:src:dst		translates "-Lsrc" into "-Ldst"
#	l:foo:bar[:baz1...]	translates "-lfoo" into "-lbar [-lbaz...]"
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

_sep=" 	\`\"':;,"

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
s|^$2\([/$_sep]\)|$3\1|g
s|^$2$|$3|g
s|\([$_sep]\)$2\([/$_sep]\)|\1$3\2|g
s|\([$_sep]\)$2$|\1$3|g
EOF
			case "$2" in
			-*)	;;
			*)
				@CAT@ >> $sedfile << EOF
s|\(-[ILR]\)$2\([/$_sep]\)|\1$3\2|g
s|\(-[ILR]\)$2$|\1$3|g
EOF
				;;
			esac
			;;
		esac
		;;
	sub-mangle)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|^$2\(/[^/$_sep]\)|$3\1|g
s|\([$_sep]\)$2\(/[^/$_sep]\)|\1$3\2|g
EOF
			case "$2" in
			-*)	;;
			*)
				@CAT@ >> $sedfile << EOF
s|\(-[ILR]\)$2\(/[^/$_sep]\)|\1$3\2|g
EOF
				;;
			esac
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
	sub-rpath)
		gen $action sub-mangle:-Wl,--rpath-link,$2:-Wl,--rpath-link,$3
		gen $action sub-mangle:-Wl,--rpath,$2:-Wl,--rpath,$3
		gen $action sub-mangle:-Wl,-rpath-link,$2:-Wl,-rpath-link,$3
		gen $action sub-mangle:-Wl,-rpath,$2:-Wl,-rpath,$3
		gen $action sub-mangle:-Wl,-R$2:-Wl,-R$3
		gen $action sub-mangle:-R$2:-R$3
		;;
	abs-rpath)
		gen $action __r:-Wl,--rpath-link,\\.
		gen $action __r:-Wl,--rpath,\\.
		gen $action __r:-Wl,-rpath-link,\\.
		gen $action __r:-Wl,-rpath,\\.
		gen $action __r:-Wl,-R\\.
		gen $action __r:-R\\.
		;;
	no-rpath)
		gen $action __r:-Wl,--rpath-link,
		gen $action __r:-Wl,--rpath,
		gen $action __r:-Wl,-rpath-link,
		gen $action __r:-Wl,-rpath,
		gen $action __r:-Wl,-R
		gen $action __r:-R
		;;
	reorder)
		case "$action" in
		transform)
			shift
			case $1 in
			l)
				@CAT@ >> $reorderlibs << EOF
		# -l$2 comes before -l$3
		-l$2)
			case "\${_libs}" in
			-l$3" "*|*" "-l$3" "*)
				_libs="\${_libs%%-l$3 *}-l$2 -l$3 \${_libs#*-l$3 }"
				;;
			-l$3|*" "-l$3)
				_libs="\${_libs%%-l$3}-l$2 -l$3"
				;;
			*)
				_libs="\${_libs} \$l"
				;;
			esac
			;;
EOF
				;;
			esac
			;;
		esac
		;;
	depot)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|^$2/[^/$_sep]*\(/[^$_sep]\)|$3\1|g
s|^$2/[^/$_sep]*$|$3|g
s|\([$_sep]\)$2/[^/$_sep]*\(/[^$_sep]\)|\1$3\2|g
s|\([$_sep]\)$2/[^/$_sep]*$|\1$3|g
s|\(-[ILR]\)$2/[^/$_sep]*\(/[^$_sep]\)|\1$3\2|g
s|\(-[ILR]\)$2/[^/$_sep]*$|\1$3|g
EOF
			;;
		esac
		;;
	I|L)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|-$1$2\([$_sep]\)|-$1$3\1|g
s|-$1$2$|-$1$3|g
s|-$1$2/|-$1$3/|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|-$1$3\([$_sep]\)|-$1$2\1|g
s|-$1$3$|-$1$2|g
s|-$1$3/|-$1$2/|g
EOF
			;;
		esac
		;;
	l)
		case "$action" in
		transform|untransform)
			shift
			tolibs=
			fromlib="-l$1"; shift
			while [ $# -gt 0 ]; do
				case $1 in
				"")	;;
				*)	case $tolibs in
					"")	tolibs="-l$1" ;;
					*)	tolibs="$tolibs -l$1"
					esac
					;;
				esac
				shift
			done
			@CAT@ >> $sedfile << EOF
s|$fromlib\([$_sep]\)|$tolibs\1|g
s|$fromlib$|$tolibs|g
EOF
			;;
		esac
		;;
	P)
		case "$action" in
		transform)
			@CAT@ >> $sedfile << EOF
s|$2\(/[^$_sep]*/lib[^/$_sep]*\.la\)\([$_sep]\)|$3\1\2|g
s|$2\(/[^$_sep]*/lib[^/$_sep]*\.la\)$|$3\1|g
s|$2\(/[^$_sep]*/lib[^/$_sep]*\.a\)\([$_sep]\)|$3\1\2|g
s|$2\(/[^$_sep]*/lib[^/$_sep]*\.a\)$|$3\1|g
EOF
			;;
		untransform)
			@CAT@ >> $sedfile << EOF
s|$3\(/[^$_sep]*/lib[^/$_sep]*\.a\)\([$_sep]\)|$2\1\2|g
s|$3\(/[^$_sep]*/lib[^/$_sep]*\.a\)$|$2\1|g
s|$3\(/[^$_sep]*/lib[^/$_sep]*\.la\)\([$_sep]\)|$2\1\2|g
s|$3\(/[^$_sep]*/lib[^/$_sep]*\.la\)$|$2\1|g
EOF
			;;
		esac
		;;
	p)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|\($2/[^$_sep]*\)/lib\([^/$_sep]*\)\.so\(\.[0-9]*\)*\([$_sep]\)|-L\1 -l\2\4|g
s|\($2/[^$_sep]*\)/lib\([^/$_sep]*\)\.so\(\.[0-9]*\)*$|-L\1 -l\2|g
s|\($2\)/lib\([^/$_sep]*\)\.so\(\.[0-9]*\)*\([$_sep]\)|-L\1 -l\2\4|g
s|\($2\)/lib\([^/$_sep]*\)\.so\(\.[0-9]*\)*$|-L\1 -l\2|g
s|\($2/[^$_sep]*\)/lib\([^/$_sep]*\)\.dylib\([$_sep]\)|-L\1 -l\2\3|g
s|\($2/[^$_sep]*\)/lib\([^/$_sep]*\)\.dylib$|-L\1 -l\2|g
s|\($2\)/lib\([^/$_sep]*\)\.dylib\([$_sep]\)|-L\1 -l\2\3|g
s|\($2\)/lib\([^/$_sep]*\)\.dylib$|-L\1 -l\2|g
EOF
			;;
		esac
		;;
	__r)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2[^$_sep]*||g
EOF
			;;
		esac
		;;
	_r)
		case "$action" in
		transform|untransform)
			@CAT@ >> $sedfile << EOF
s|$2\([$_sep]\)|\1|g
s|$2$||g
s|$2/[^$_sep]*||g
EOF
			;;
		esac
		;;
	r)
		case "$2" in
		*/)	r=__r ;;
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
s|$2\([$_sep]\)|$3\1|g
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

# Write out header for reorderlibs 
@CAT@ > $reorderlibs << EOF
\$echo "==> Reordering libraries: \$libs" >> \$wrapperlog
prevlibs=
while \$test "\$libs" != "\$prevlibs"; do
	_libs=
	for l in \$libs; do
		case \$l in
EOF

# Parse arguments
for arg do
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

# Write out footer for reorderlibs 
@CAT@ >> $reorderlibs << EOF
		*)
			_libs="\${_libs} \$l"
			;;
		esac
		_libs="\${_libs# }"
		_libs="\${_libs% }"
	done
	prevlibs="\$libs"
	libs="\${_libs}"
done

# This section suppress duplicate libraries in sequence.
_libs=
for l in \$libs; do
	case "\${_libs}" in
	\$l|*" "\$l) ;;
	*) _libs="\${_libs} \$l" ;;
	esac
done
_libs="\${_libs# }"
_libs="\${_libs% }"
libs="\${_libs}"
EOF
