#! /bin/sh
# $NetBSD: shquote.sh,v 1.1 2019/03/24 11:29:19 rillig Exp $

# Quotes all shell meta characters from $1 and writes the result to $shquoted.
shquote()
{
	shquoted=$1
	case $shquoted in
	*\'*)
		shquoted=`$tools_wrapper_sed -e 's,'\'','\''\\\\'\'''\'',g' <<EOF
$shquoted
EOF`
	esac

	case $shquoted in
	*[!!%+,\-./0-9:=@A-Z_a-z]*|'')
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
