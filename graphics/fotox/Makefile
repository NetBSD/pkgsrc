# $NetBSD: Makefile,v 1.1.1.1 2007/12/17 19:45:08 drochner Exp $
#

DISTNAME=	fotox.32
PKGNAME=	fotox-32
CATEGORIES=	graphics
MASTER_SITES=	http://kornelix.squarespace.com/storage/fotox/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kornelix.squarespace.com/fotox/
COMMENT=	Simple image manipulation program

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

FDATA=		${PREFIX}/share/fotox

SUBST_CLASSES+=		data
SUBST_STAGE.data=	pre-build
SUBST_FILES.data=	zlib.cpp
SUBST_VARS.data=	FDATA

do-build:
	(cd ${WRKSRC} && ${SH} fotox-build.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fotox.x ${PREFIX}/bin/fotox
	${INSTALL_DATA_DIR} ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/parameters.txt ${FDATA}
	${CP} -r ${WRKSRC}/icons ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/fotox-guide.pdf ${FDATA}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
