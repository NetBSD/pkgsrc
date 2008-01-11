# $NetBSD: Makefile,v 1.3 2008/01/11 13:14:39 drochner Exp $
#

DISTNAME=	fotox.34
PKGNAME=	fotox-34
CATEGORIES=	graphics
MASTER_SITES=	http://kornelix.squarespace.com/storage/fotox/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kornelix.squarespace.com/fotox/
COMMENT=	Simple image manipulation program

WRKSRC=		${WRKDIR}/fotox
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

FDATA=		${PREFIX}/share/fotox

SUBST_CLASSES+=		data
SUBST_STAGE.data=	pre-build
SUBST_FILES.data=	zfuncs.cpp
SUBST_VARS.data=	FDATA

do-build:
	(cd ${WRKSRC} && ${SH} build ${PREFIX} y)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fotox ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/parameters.txt ${FDATA}
	${CP} -r ${WRKSRC}/icons ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/fotox-guide.pdf ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/*.xtext ${FDATA}
	${INSTALL_DATA} ${WRKSRC}/fotox.desktop ${PREFIX}/share/applications

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
