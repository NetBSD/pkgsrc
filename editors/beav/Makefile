# New ports collection makefile for:	beav
# Version required:	1.40-11 (debian)
# Date created:		01 July 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $NetBSD: Makefile,v 1.2 1998/12/20 21:12:57 bad Exp $
# FreeBSD Id: Makefile,v 1.12 1998/08/23 02:10:57 hoek Exp 
#

DISTNAME=	beav_1.40-11
PKGNAME=	beav-1.40.11
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.debian.org/debian/hamm/hamm/source/editors/

MAINTAINER=	bad@NetBSD.ORG

WRKSRC=		${WRKDIR}/beav-1.40

MAKE_ENV+=	SED="${SED}"

pre-patch:
	${MV} ${WRKSRC}/beav.1 ${WRKSRC}/beav.1.in

.include "../../mk/bsd.pkg.mk"
