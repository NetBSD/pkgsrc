# $NetBSD: Makefile,v 1.44 2023/10/24 22:10:58 wiz Exp $

PKGNAME=	qca2-ossl-${DISTNAME:C/.*-//}
PKGREVISION=	6

COMMENT=	Cross-platform crypto API for QT - OpenSSL plugin

.include "../../security/qca2/Makefile.common"

BUILD_DIRS=	plugins/qca-ossl

CMAKE_ARGS+=	-DQT4_BUILD=ON
CMAKE_ARGS+=	-DBUILD_PLUGINS=ossl
CMAKE_ARGS+=	-DBUILD_TOOLS=OFF
CMAKE_ARGS+=	-DINST_QCA_LIB_NAME=-lqca

SUBST_CLASSES+=		libname
SUBST_STAGE.libname=	pre-configure
SUBST_MESSAGE.libname=	Use installed lib.
SUBST_FILES.libname=	plugins/qca-ossl/CMakeLists.txt
SUBST_SED.libname=	-e 's:{QCA_LIB_NAME}:{INST_QCA_LIB_NAME}:'

.include "../../security/qca2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
