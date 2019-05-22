#! /bin/sh
# $NetBSD: shquote.sh,v 1.2 2019/05/22 20:47:05 rillig Exp $

# Quotes all shell meta characters from $1 and writes the result to $shquoted.
shquote()
{
	shquoted=$1
	case $shquoted in
	*\'*)
		# replace each ' with '\''
		shquoted=`$tools_wrapper_sed -e "s,','\\\\\\\\'',g" <<EOF
$shquoted
EOF`
	esac

	case $shquoted in
	(*[!!%+,\-./0-9:=@A-Z_a-z]*|'')

		# Move the single quote after the first equals sign, so that
		# macro definitions look like -DMACRO='"value"' instead of
		# the less common '-DMACRO="value"'.
		case $shquoted in
		(*=*)	lhs=${shquoted%%=*}
			case $lhs in
			(*[!!%+,\-./0-9:=@A-Z_a-z]*|'') ;;
			(*)	shquoted="$lhs='${shquoted#*=}'"
				return
			esac
		esac

		shquoted="'$shquoted'"
	esac
}

shquote_args() {
	shquoted_args=''
	for arg in "$@"; do
		shquote "$arg"
		shquoted_args="$shquoted_args $shquoted"
	done
}
