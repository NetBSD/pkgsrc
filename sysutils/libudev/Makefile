# $NetBSD: Makefile,v 1.4 2023/07/22 08:41:13 nia Exp $

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

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

BUILD_DEFS+=	VARBASE

ONLY_FOR_PLATFORM=	Linux-*-*
USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-rootrundir=${VARBASE}/run

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# missing: libkmod?
.include "../../mk/bsd.pkg.mk"
