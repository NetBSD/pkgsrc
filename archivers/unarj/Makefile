# New ports collection makefile for:    unarj
# Version required:     2.41
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $NetBSD: Makefile,v 1.2 1997/10/27 03:22:22 hubertf Exp $
# FreeBSD Id: Makefile,v 1.6 1996/11/12 02:17:38 obrien Exp 
#

DISTNAME=       unarj
PKGNAME=	unarj-2.41
CATEGORIES=	archivers
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
DISTFILES=      unarj241.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
