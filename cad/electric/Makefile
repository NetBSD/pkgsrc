# $NetBSD: Makefile,v 1.22 2020/01/18 23:30:10 rillig Exp $
#

DISTNAME=	electric-7.00
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU:=electric/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/electric/electric.html
COMMENT=	Electrical CAD system

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++

post-patch:
	${MV} ${WRKSRC}/src/include/config.h ${WRKSRC}/src/include/config.h.bak
	${SED}  -e 's;@prefix@;${PREFIX};g' \
		-e 's;@localbase@;${PREFIX};g' \
		< ${WRKSRC}/src/include/config.h.bak \
		> ${WRKSRC}/src/include/config.h

INSTALL_TARGET=		install install.html
INSTALLATION_DIRS=	bin

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
