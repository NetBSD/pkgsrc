# $NetBSD: Makefile,v 1.4 2001/02/16 14:40:49 wiz Exp $
# FreeBSD Id: Makefile,v 1.12 1998/08/23 02:10:57 hoek Exp 
#

DISTNAME=	beav_1.40-11
PKGNAME=	beav-1.40.11
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.debian.org/debian/hamm/hamm/source/editors/

MAINTAINER=	bad@NetBSD.ORG
COMMENT=	Binary Editor And Viewer, a full featured binary file editor

WRKSRC=		${WRKDIR}/beav-1.40

MAKE_ENV+=	SED="${SED}"

pre-patch:
	${MV} ${WRKSRC}/beav.1 ${WRKSRC}/beav.1.in

.include "../../mk/bsd.pkg.mk"
