# $NetBSD: Makefile,v 1.7 2004/04/11 19:08:15 snj Exp $
#

DISTNAME=	electric-6.05
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${LOCALBASE};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.html

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
