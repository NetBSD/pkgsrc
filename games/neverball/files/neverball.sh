# !/bin/sh
#
# $NetBSD: neverball.sh,v 1.1.1.1 2004/04/18 05:02:55 xtraeme Exp $

progname=$(basename $0)

usage()
{
    cat <<_EOF
Usage: ${progname} -x [game]

There are two games to play, \`neverball' and \`neverputt',
you can choose any of them via -c flag, i.e:

    ${progname} -x ball
    ${progname} -x putt

Enjoy!

_EOF
}

args=`getopt x: $*`

set -- $args
while [ $# -gt 0 ]; do
        case "$1" in
            -x)
                game="$2"
		case "$game" in
			ball)
			    cd @SHAREDIR@ && exec ./neverball
			;;
			putt)
			    cd @SHAREDIR@ && exec ./neverputt
			;;
		esac
                shift
                ;;
            --)
                shift; break
                ;;
        esac
        shift
done

if [ $? -lt 1 ]; then
	usage
fi

exit 0
