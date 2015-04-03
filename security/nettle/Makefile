# $NetBSD: Makefile,v 1.14 2015/04/03 18:34:14 mrg Exp $

DISTNAME=	nettle-2.7.1
PKGREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.lysator.liu.se/~nisse/archive/ \
		ftp://ftp.lysator.liu.se/pub/security/lsh/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lysator.liu.se/~nisse/nettle/
COMMENT=	Cryptographic library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gm4 gmake
GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
CONFIGURE_ARGS+=	--disable-openssl --disable-shared

.if (${MACHINE_ARCH} == "earmv4" || ${MACHINE_ARCH} == "armv4")
CONFIGURE_ARGS+=	--disable-assembler
.endif

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

INFO_FILES=		yes
TEST_TARGET=		check
PKGCONFIG_OVERRIDE=	hogweed.pc.in
PKGCONFIG_OVERRIDE+=	nettle.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
