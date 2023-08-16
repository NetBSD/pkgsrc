# $NetBSD: Makefile,v 1.41 2023/08/16 01:01:35 gutteridge Exp $

DISTNAME=	cdparanoia-III-10.2
PKGNAME=	cdparanoia-3.0.10.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/cdparanoia/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
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
