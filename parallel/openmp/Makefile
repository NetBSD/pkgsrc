# $NetBSD: Makefile,v 1.24 2025/05/09 19:37:14 wiz Exp $

PKGREVISION= 1
.include "../../lang/llvm/version.mk"

DISTNAME=	openmp-${LLVM_VERSION}.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	parallel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://openmp.llvm.org/
COMMENT=	Support for the OpenMP language
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c gnu++17
USE_TOOLS+=		perl pkg-config
GCC_REQD+=		7	# Not supported by ancient GCCs

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DOPENMP_ENABLE_LIBOMPTARGET=OFF
CMAKE_CONFIGURE_ARGS+=	-DOPENMP_ENABLE_OMPT_TOOLS=OFF

BUILDLINK_TRANSFORM.NetBSD+=	opt:-std=c++17:-std=gnu++17 # alloca

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
