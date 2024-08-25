# $NetBSD: Makefile,v 1.6 2024/08/25 06:18:54 wiz Exp $

DISTNAME=	soapy-sdr-0.8.1
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

SUBST_CLASSES+=		getopt
SUBST_STAGE.getopt=	pre-configure
SUBST_MESSAGE.getopt=	Fixing getopt_long_only
SUBST_FILES.getopt+=	apps/SoapySDRUtil.cpp
SUBST_SED.getopt+=	-e s,getopt_long_only,getopt_long,

# boost's posix_thread header causes pthread_create() reference
LDFLAGS+=		-lpthread

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
