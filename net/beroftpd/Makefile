# $NetBSD: Makefile,v 1.2 1999/03/07 16:51:44 rh Exp $
# FreeBSD Id: Makefile,v 1.3 1999/02/23 22:12:30 billf Exp
#

DISTNAME=	BeroFTPD-1.3.4
PKGNAME=	beroftpd-1.3.4
CATEGORIES=	net
MASTER_SITES=	ftp://bero.x5.net/pub/ \
		ftp://ftp.croftj.net/usr/bero/BeroFTPD/ \
		ftp://ftp.kddlabs.co.jp/.2/inet/ftp/BeroFTPD/ \
		ftp://ftp.rediris.es/mirror/BeroFTPD/ \
		ftp://sunsite.cnlab-switch.ch/mirror/BeroFTPD/ \
		ftp://ftp.startrek.eu.org/pub/BeroFTPD/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.landfield.com/wu-ftpd/

CONFLICTS+=	wu-ftpd-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-confdir=${PREFIX}/etc

.include "../../mk/bsd.pkg.mk"
