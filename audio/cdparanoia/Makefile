# $NetBSD: Makefile,v 1.38 2017/08/01 14:58:52 wiz Exp $

DISTNAME=	cdparanoia-III-10.2
PKGNAME=	cdparanoia-3.0.10.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/cdparanoia/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	https://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

CONFIG_GUESS_OVERRIDE=	configure.guess
CONFIG_SUB_OVERRIDE=	configure.sub

# If this is not *supportable* on other platforms, please document why here.
BROKEN_EXCEPT_ON_PLATFORM=	NetBSD-*-* FreeBSD-*-* DragonFly-*-*
BROKEN_EXCEPT_ON_PLATFORM+=	Linux-*-* Darwin-*-* SunOS-*-*

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes
CFLAGS+=	-Dprivate_data=private

CFLAGS.SunOS+=		-Du_int16_t=uint16_t -Du_int32_t=uint32_t -DCDDA_TEST

LDFLAGS.FreeBSD+=	-lcam
LDFLAGS.DragonFly+=	-lcam

.include "../../mk/bsd.pkg.mk"
