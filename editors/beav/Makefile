# $NetBSD: Makefile,v 1.8 2004/01/20 12:14:05 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1998/08/23 02:10:57 hoek Exp
#

DISTNAME=	beav_1.40-11
PKGNAME=	beav-1.40.11
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_DEBIAN:=hamm/hamm/source/editors/}

MAINTAINER=	bad@NetBSD.ORG
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

WRKSRC=		${WRKDIR}/beav-1.40
MAKE_ENV+=	SED="${SED}"

pre-patch:
	${MV} ${WRKSRC}/beav.1 ${WRKSRC}/beav.1.in

.include "../../mk/bsd.pkg.mk"
