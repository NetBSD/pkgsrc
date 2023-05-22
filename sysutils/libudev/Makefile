# $NetBSD: Makefile,v 1.3 2023/05/22 16:32:23 nikita Exp $

DISTNAME=	libudev-3.2.12
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eudev-project/}
GITHUB_PROJECT=	eudev
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTINFO_FILE=	${.CURDIR}/../../sysutils/libudev/distinfo

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://github.com/eudev-project/eudev/
LICENSE=	gnu-gpl-v2
COMMENT=	Device enumeration and database of constants

BUILD_DEFS+=	VARBASE

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-rootrundir=${VARBASE}/run

SUBST_CLASSES+=		nogperf
SUBST_STAGE.nogperf=	pre-configure
SUBST_FILES.nogperf=	configure.ac
SUBST_SED.nogperf=	-e 's,ERROR\(.*gperf\),WARN\1,'

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# missing: libkmod?
.include "../../mk/bsd.pkg.mk"
