# $NetBSD: Makefile,v 1.7 2026/08/08 07:14:51 wiz Exp $

DISTNAME=	ggml-0.19.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggml-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggml-org/ggml/
COMMENT=	Tensor library for machine learning
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17

PKGCONFIG_OVERRIDE+=	ggml.pc.in

CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes

SUBST_CLASSES+=		findblas
SUBST_STAGE.findblas=	pre-configure
SUBST_MESSAGE.findblas=	Fixing libpci soname
SUBST_FILES.findblas+=	src/ggml-blas/CMakeLists.txt
SUBST_SED.findblas+=	-e 's,DepBLAS openblas64,DepBLAS ${BLAS_PC},'

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
