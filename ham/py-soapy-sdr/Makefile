# $NetBSD: Makefile,v 1.1 2020/08/01 08:57:05 tnn Exp $

DISTNAME=	soapy-sdr-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=pothosware/}
GITHUB_PROJECT=	SoapySDR
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pothosware/SoapySDR/wiki/PythonSupport
COMMENT=	Python bindings for SoapySDR
LICENSE=	boost-license

BUILD_DEPENDS+=	swig3-[0-9]*:../../devel/swig3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

CMAKE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN:Q}
CMAKE_ARGS+=	-DPYTHON_CONFIG_EXECUTABLE=${PYTHONBIN:Q}-config
CMAKE_ARGS+=	-DSWIG_EXECUTABLE=${PREFIX:Q}/bin/swig3.0
WRKSRC=		${WRKDIR}/SoapySDR-${DISTNAME}/python

.include "../../lang/python/extension.mk"
PY_PATCHPLIST=	yes

.include "../../ham/soapy-sdr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
