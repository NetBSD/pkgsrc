# $NetBSD: Makefile,v 1.11 2005/12/05 20:50:09 rillig Exp $

DISTNAME=	beav_1.40-11
PKGNAME=	beav-1.40.11
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_DEBIAN:=hamm/hamm/source/editors/}

MAINTAINER=	bad@NetBSD.org
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

WRKSRC=		${WRKDIR}/beav-1.40
MAKE_ENV+=	SED=${SED:Q}

pre-patch:
	${MV} ${WRKSRC}/beav.1 ${WRKSRC}/beav.1.in

.include "../../mk/bsd.pkg.mk"
