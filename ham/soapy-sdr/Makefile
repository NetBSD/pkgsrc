# $NetBSD: Makefile,v 1.2 2020/08/01 08:17:43 tnn Exp $

DISTNAME=	soapy-sdr-0.7.2
PKGREVISION=	1
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
.include "../../mk/bsd.pkg.mk"
