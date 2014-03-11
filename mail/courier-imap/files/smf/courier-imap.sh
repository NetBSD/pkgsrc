#!@SMF_METHOD_SHELL@
#
# $NetBSD: courier-imap.sh,v 1.1 2014/03/11 14:34:38 jperkin Exp $
#
# Init script for Courier-IMAP.
#

. /lib/svc/share/smf_include.sh

prefix=@PREFIX@
exec_prefix=@PREFIX@
bindir=${exec_prefix}/bin
sbindir=${exec_prefix}/sbin

case "$1" in
start)
        cd /
        . $prefix/etc/courier/imapd

        printf "Starting Courier-IMAP server:"

        case x$IMAPDSTART in
        x[yY]*)
                # Start daemons.
                $sbindir/imapd start
                printf "\n imap"
                ;;
        esac

        . $prefix/etc/courier/imapd-ssl
        case x$IMAPDSSLSTART in
        x[yY]*)
                if test -x $COURIERTLS
                then

                # First time we start this, generate a dummy SSL certificate.

                        if test ! -f $TLS_CERTFILE
                        then
                                printf "\n generating-SSL-certificate..."
                                $prefix/share/courier/mkimapdcert >/dev/null 2>&1
                        fi
                        $sbindir/imapd-ssl start
                        printf "\n imap-ssl"
                fi
                ;;
        esac

        POP3DSTART=""
        POP3DSSLSTART=""

        if test -f $prefix/etc/courier/pop3d
        then
                . $prefix/etc/courier/pop3d
        fi

        case x$POP3DSTART in
        x[yY]*)
                # Start daemons.
                $sbindir/pop3d start
                printf "\n pop3"
                ;;
        esac

        if test -f $prefix/etc/courier/pop3d-ssl
        then
                . $prefix/etc/courier/pop3d-ssl
        fi

        case x$POP3DSSLSTART in
        x[yY]*)
                if test -x $COURIERTLS
                then

                # First time we start this, generate a dummy SSL certificate.

                        if test ! -f $TLS_CERTFILE
                        then
                                printf "\n generating-SSL-certificate..."
                                $prefix/share/courier/mkpop3dcert >/dev/null 2>&1
                        fi
                        $sbindir/pop3d-ssl start
                        printf "\n pop3-ssl"
                fi
                ;;
        esac

        echo ""
        ;;
stop)
        printf "Stopping Courier-IMAP server:"
        . $prefix/etc/courier/imapd
        . $prefix/etc/courier/imapd-ssl
        $sbindir/imapd stop
        printf "\n imap"
        if test -x $COURIERTLS
        then
                $sbindir/imapd-ssl stop
                printf "\n imap-ssl"
        fi

        if test -f $prefix/etc/courier/pop3d
        then
                $sbindir/pop3d stop
                printf "\n pop3"

                if test -x $COURIERTLS
                then
                        $sbindir/pop3d-ssl stop
                        printf "\n pop3-ssl"
                fi
        fi

        echo ""
        ;;
restart)
        $0 stop
        sleep 3
        $0 start
        ;;
esac
exit 0
