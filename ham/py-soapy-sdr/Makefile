# $NetBSD: Makefile,v 1.8 2025/08/19 13:25:33 wiz Exp $

DISTNAME=	soapy-sdr-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=pothosware/}
GITHUB_PROJECT=	SoapySDR
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pothosware/SoapySDR/wiki/PythonSupport
COMMENT=	Python bindings for SoapySDR
LICENSE=	boost-license

USE_LANGUAGES+=		c++
USE_CXX_FEATURES+=	c++11
FORCE_CXX_STD=		c++11

TOOL_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

# Perhaps should be CONFIGURE_DIR, in part.
WRKSRC=		${WRKDIR}/SoapySDR-${DISTNAME}/python

.include "../../devel/cmake/build.mk"
# \todo Are these really necessary?
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN:Q}
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_CONFIG_EXECUTABLE=${PYTHONBIN:Q}-config
CMAKE_CONFIGURE_ARGS+=	-DSWIG_EXECUTABLE=${PREFIX:Q}/bin/swig3.0
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_INSTALL_DIR=${PREFIX:Q}/${PYSITELIB}
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"

.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
