# $NetBSD: Makefile,v 1.34 2016/02/05 09:08:56 nonaka Exp $

DISTNAME=	keepassx-2.0.2
CATEGORIES=	security x11
MASTER_SITES=	https://www.keepassx.org/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.keepassx.org/
COMMENT=	Password generator and manager v2 (kdbx support)
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	build

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
