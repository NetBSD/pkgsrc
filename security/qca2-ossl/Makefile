# $NetBSD: Makefile,v 1.48 2025/04/24 14:15:41 wiz Exp $

PKGNAME=	qca2-ossl-${DISTNAME:C/.*-//}
PKGREVISION=	8

COMMENT=	Cross-platform crypto API for QT - OpenSSL plugin

BROKEN=		"Does not compile against openssl 3"

.include "../../security/qca2/Makefile.common"

BUILD_DIRS=	plugins/qca-ossl

CMAKE_CONFIGURE_ARGS+=	-DQT4_BUILD=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PLUGINS=ossl
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TOOLS=OFF
CMAKE_CONFIGURE_ARGS+=	-DINST_QCA_LIB_NAME=-lqca

SUBST_CLASSES+=		libname
SUBST_STAGE.libname=	pre-configure
SUBST_MESSAGE.libname=	Use installed lib.
SUBST_FILES.libname=	plugins/qca-ossl/CMakeLists.txt
SUBST_SED.libname=	-e 's:{QCA_LIB_NAME}:{INST_QCA_LIB_NAME}:'

.include "../../security/qca2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
