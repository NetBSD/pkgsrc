# $NetBSD: Makefile,v 1.29 2021/12/08 16:06:23 adam Exp $

PKGNAME=	qca2-gnupg-${DISTNAME:C/.*-//}
PKGREVISION=	4

COMMENT=	Cross-platform crypto API for QT - GnuPG plugin

.include "../../security/qca2/Makefile.common"

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

BUILD_DIRS=	plugins/qca-gnupg

CMAKE_ARGS+=	-DQT4_BUILD=ON
CMAKE_ARGS+=	-DBUILD_PLUGINS=gnupg
CMAKE_ARGS+=	-DBUILD_TOOLS=OFF
CMAKE_ARGS+=	-DINST_QCA_LIB_NAME=-lqca

SUBST_CLASSES+=		libname
SUBST_STAGE.libname=	pre-configure
SUBST_MESSAGE.libname=	Use installed lib.
SUBST_FILES.libname=	plugins/qca-gnupg/CMakeLists.txt
SUBST_SED.libname=	-e 's:{QCA_LIB_NAME}:{INST_QCA_LIB_NAME}:'

.include "../../security/qca2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
