# $NetBSD: Makefile,v 1.5 2025/05/04 07:18:03 vins Exp $

DISTNAME=	libudev-3.2.14
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
USE_TOOLS+=		autoconf automake gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

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
