# $NetBSD: Makefile,v 1.15 2006/07/22 04:46:14 rillig Exp $
#

DISTNAME=	electric-7.00
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${LOCALBASE};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.html

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
