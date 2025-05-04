# $NetBSD: Makefile,v 1.6 2025/05/04 09:57:54 vins Exp $

DISTNAME=	libudev-3.2.14
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=eudev-project/}
GITHUB_PROJECT=	eudev
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nykula@ukr.net
HOMEPAGE=	https://github.com/eudev-project/eudev/
LICENSE=	gnu-gpl-v2
COMMENT=	Device enumeration and database of constants

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

BUILD_DEFS+=	VARBASE

ONLY_FOR_PLATFORM=	Linux-*-*

USE_LANGUAGES=	c c++

USE_TOOLS+=		autoconf automake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	src/libudev/libudev.pc.in

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing udev rules.d prefix.
SUBST_FILES.prefix=	src/udev/udev-rules.c
SUBST_SED.prefix+=	-e "s:/usr/local/lib:${PREFIX}/lib:"

CONFIGURE_ARGS+=	--with-rootrundir=${VARBASE}/run

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

# missing: libkmod?
.include "../../mk/bsd.pkg.mk"
