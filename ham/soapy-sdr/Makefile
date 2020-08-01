# $NetBSD: Makefile,v 1.1 2020/08/01 07:46:14 tnn Exp $

DISTNAME=	soapy-sdr-0.7.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=pothosware/}
GITHUB_PROJECT=	SoapySDR
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pothosware/SoapySDR/wiki
COMMENT=	Vendor and platform neutral SDR support library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

# Uses PyObject_Compare() (Supports python 3.8 in master branch)
PYTHON_VERSIONS_ACCEPTED=	27
PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"

.if !empty(_PYTHON_VERSION:M3*)
CMAKE_ARGS+=	-DPYTHON3_EXECUTABLE=${PYTHONBIN:Q}
CMAKE_ARGS+=	-DPYTHON3_LIBRARIES=${PREFIX:Q}/${PYLIB:Q}
CMAKE_ARGS+=	-DPYTHON3_INCLUDE_DIRS=${PREFIX:Q}/${PYINC:Q}
.endif

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	apps/SoapySDRUtil.cpp
SUBST_SED.getopt+=	-e s,getopt_long_only,getopt_long,

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Fixing manpage directory
SUBST_FILES.mandir+=	apps/CMakeLists.txt
SUBST_SED.mandir+=	-e 's,share/man,${PKGMANDIR},'

# boost's posix_thread header causes pthread_create() reference
LDFLAGS+=		-lpthread

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
