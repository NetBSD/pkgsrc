# New ports collection makefile for:    PNG images library
# Version required:     0.96
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.5 1998/02/02 08:59:21 hubertf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:44 max Exp
#

DISTNAME=       libpng-0.96
PKGNAME=        png-0.96
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
EXTRACT_SUFX=   .tgz

MAINTAINER=     ache@FreeBSD.org

MAKEFILE=       makefile

post-install:
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
