# $NetBSD: Makefile,v 1.3 2002/09/21 06:05:55 jlam Exp $
#

DISTNAME=	electric-6.05
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${LOCALBASE};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

post-install:
	cd ${WRKSRC} && ${ENV} ${MAKE_ENV} ${MAKE_PROGRAM} install.html

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
