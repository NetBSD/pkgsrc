# New ports collection makefile for:   beroftpd
# Version required:    1.2.1
# Date created:        6 November 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1999/03/07 16:49:17 rh Exp $
#

DISTNAME=	BeroFTPD-1.3.3
PKGNAME=	beroftpd-1.3.3
CATEGORIES=	net
MASTER_SITES=	ftp://beroftpd.unix.eu.org/pub/BeroFTPD/ \
		ftp://ftp.croftj.net/usr/bero/BeroFTPD/ \
		ftp://ftp.kddlabs.co.jp/.2/inet/ftp/BeroFTPD/ \
		ftp://ftp.rediris.es/mirror/BeroFTPD/ \
		ftp://sunsite.cnlab-switch.ch/mirror/BeroFTPD/ \
		ftp://ftp.startrek.eu.org/pub/BeroFTPD/

MAINTAINER=	billf@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-confdir=${PREFIX}/etc

MAN1=	ftpcount.1 ftpwho.1
MAN5=	ftpaccess.5 ftpconversions.5 ftphosts.5 xferlog.5 \
	ftpservers.5
MAN8=	ftpd.8 ftpshut.8 ftprestart.8

.include <bsd.port.mk>
