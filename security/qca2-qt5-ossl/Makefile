# $NetBSD: Makefile,v 1.33 2024/08/25 06:19:13 wiz Exp $

PKGNAME=	qca2-qt5-ossl-${DISTNAME:C/.*-//}
PKGREVISION=	1

COMMENT=	Cross-platform crypto API for Qt5 - OpenSSL plugin

BUILD_DIRS=	plugins/qca-ossl

.include "../../security/qca2-qt5/Makefile.common"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PLUGINS=ossl
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TOOLS=OFF
CMAKE_CONFIGURE_ARGS+=	-DINST_QCA_LIB_NAME=-lqca-qt5

SUBST_CLASSES+=		libname
SUBST_STAGE.libname=	pre-configure
SUBST_MESSAGE.libname=	Use installed lib.
SUBST_FILES.libname=	plugins/qca-ossl/CMakeLists.txt
SUBST_SED.libname=	-e 's:{QCA_LIB_NAME}:{INST_QCA_LIB_NAME}:'

.include "../../security/openssl/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
