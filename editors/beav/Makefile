# $NetBSD: Makefile,v 1.3 1999/03/08 10:49:24 agc Exp $
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
