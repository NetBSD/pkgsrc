# New ports collection makefile for:	sniffit
# Version required:	0.3.5
# Date created:		28 Mar 1998
# Whom:			bsdx
#
# $NetBSD: Makefile,v 1.1 1998/03/30 08:47:37 hubertf Exp $
# FreeBSD 
#

DISTNAME=	sniffit.0.3.5
CATEGORIES=	security
MASTER_SITES=	http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=	packages@netbsd.org


do-build:
	cd ${WRKSRC} ; ./configure ; make

do-install:
	cd ${WRKSRC} ; cp sniffit ${PREFIX}/sbin/sniffit
	chmod 555 ${PREFIX}/sbin/sniffit
	chown bin.bin ${PREFIX}/sbin/sniffit

.include <bsd.port.mk>
