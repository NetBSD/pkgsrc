# $NetBSD: Makefile,v 1.5 2025/02/06 22:44:51 mef Exp $

DISTNAME=	pytorch-v2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S,pytorch-v,torch-,}
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=pytorch/}
GITHUB_PROJECT=	pytorch
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://pytorch.org/
COMMENT=	Tensors and Dynamic neural networks in Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-sympy-[0-9]*:../../math/py-sympy
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dill-[0-9]*:../../textproc/py-dill

USE_TOOLS+=	gmake

EGG_INFODIR=	torch-2.5.0a0+gitunknown-py${PYVERSSUFFIX}.egg-info

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread openblas_openmp

USE_LANGUAGES+=		c c++
USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++17
# configure script is asking for gcc-9.3 (on NetBSD/amd64 9.3) as:
#   GCC-9.3 or newer is required to compile PyTorch, but found 7.5.0
# so:
GCC_REQD+=		10

SUBST_CLASSES+=		blas
SUBST_STAGE.blas=	pre-configure
SUBST_FILES.blas=	cmake/Modules/FindBLAS.cmake
SUBST_VARS.blas=	BLAS_PC

SUBST_CLASSES+=		amd64
SUBST_STAGE.amd64=	pre-configure
SUBST_FILES.amd64+=	CMakeLists.txt
SUBST_FILES.amd64+=	cmake/Dependencies.cmake
SUBST_FILES.amd64+=	third_party/pthreadpool/CMakeLists.txt
SUBST_FILES.amd64+=	third_party/XNNPACK/CMakeLists.txt
SUBST_FILES.amd64+=	third_party/cpuinfo/CMakeLists.txt
SUBST_FILES.amd64+=	third_party/fbgemm/third_party/cpuinfo/CMakeLists.txt
SUBST_SED.amd64=	-e 's/AMD64/amd64/g'

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

CONFIGURE_ENV+=		OpenBLAS_HOME=${BUILDLINK_DIR}
#CMAKE_CONFIGURE_ARGS+=	-DBUILD_CUSTOM_PROTOBUF=OFF
CMAKE_CONFIGURE_ARGS+=	-DBLAS_SET_BY_USER=FALSE
CMAKE_CONFIGURE_ARGS+=	-DUSE_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_CUDA=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_ROCM=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_MKLDNN=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_PYBIND11=ON
CMAKE_CONFIGURE_ARGS+=	-Dpybind11_INCLUDE_DIR=${BUILDLINK_DIR}/${PYSITELIB}/pybind11/include

MAKE_ENV+=	USE_MKLDNN=0
MAKE_ENV+=	BUILD_TEST=0
MAKE_ENV+=	USE_CUDNN=0
MAKE_ENV+=	USE_QNNPACK=0
MAKE_ENV+=	USE_DISTRIBUTED=1

post-extract:
	# For mkpatches(1) and developers only.
	${RM} -f ${WRKSRC}/third_party/opentelemetry-cpp/third_party/prometheus-cpp/3rdparty/civetweb/resources/cert/server_bkup.key.orig
	${RM} -f ${WRKSRC}/third_party/opentelemetry-cpp/third_party/prometheus-cpp/3rdparty/civetweb/resources/cert/client.key.orig
	${RM} -f ${WRKSRC}/third_party/opentelemetry-cpp/third_party/prometheus-cpp/3rdparty/civetweb/resources/cert/server.key.orig

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/protoc*
	${RM} -f ${DESTDIR}${PREFIX}/lib/libproto*.a
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/fmt.pc
	${RM} -f ${DESTDIR}${PREFIX}/lib/pkgconfig/protobuf*.pc
	${RM} -rf ${DESTDIR}${PREFIX}/include/fmt
	${RM} -rf ${DESTDIR}${PREFIX}/include/google/protobuf
	${RM} -rf ${DESTDIR}${PREFIX}/lib/cmake/fmt
	${RM} -rf ${DESTDIR}${PREFIX}/lib/cmake/protobuf

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
#.include "../../devel/protobuf/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../parallel/openmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
