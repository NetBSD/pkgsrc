# $NetBSD: Makefile,v 1.8 2025/09/27 09:57:24 wiz Exp $

DISTNAME=	soapy-sdr-0.8.1
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=pothosware/}
GITHUB_PROJECT=	SoapySDR
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pothosware/SoapySDR/wiki
COMMENT=	Vendor and platform neutral SDR support library
LICENSE=	boost-license

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
# Do not use /lib64.  \todo File upstream bug.
CMAKE_CONFIGURE_ARGS+=	-DLIB_SUFFIX=""
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	apps/SoapySDRUtil.cpp
SUBST_SED.getopt+=	-e s,getopt_long_only,getopt_long,

# boost's posix_thread header causes pthread_create() reference
LDFLAGS+=		-lpthread

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
