# $NetBSD: Makefile,v 1.1.1.1 2002/03/13 01:39:18 dmcmahill Exp $
#

DISTNAME=	electric-6.05
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${LOCALBASE};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

post-install:
	cd ${WRKSRC} && ${ENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.html

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
