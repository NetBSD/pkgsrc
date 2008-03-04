# $NetBSD: Makefile,v 1.4 2008/03/04 15:39:09 jlam Exp $
#

DISTNAME=	fotox.34
PKGNAME=	fotox-34
CATEGORIES=	graphics
MASTER_SITES=	http://kornelix.squarespace.com/storage/fotox/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kornelix.squarespace.com/fotox/
COMMENT=	Simple image manipulation program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fotox
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

FDATA=		${PREFIX}/share/fotox

SUBST_CLASSES+=		data
SUBST_STAGE.data=	pre-build
SUBST_FILES.data=	zfuncs.cpp
SUBST_VARS.data=	FDATA

INSTALLATION_DIRS=	bin share/applications

do-build:
	(cd ${WRKSRC} && ${SH} build ${PREFIX} y)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fotox ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${FDATA}
	${INSTALL_DATA} ${WRKSRC}/parameters.txt ${DESTDIR}${FDATA}
	${CP} -r ${WRKSRC}/icons ${DESTDIR}${FDATA}
	${INSTALL_DATA} ${WRKSRC}/fotox-guide.pdf ${DESTDIR}${FDATA}
	${INSTALL_DATA} ${WRKSRC}/*.xtext ${DESTDIR}${FDATA}
	${INSTALL_DATA} ${WRKSRC}/fotox.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
