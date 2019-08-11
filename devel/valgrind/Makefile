# $NetBSD: Makefile,v 1.30 2019/08/11 13:20:52 wiz Exp $
#

DISTNAME=		valgrind-3.13.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://sourceware.org/pub/valgrind/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://valgrind.org/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-x86_64 \
			Linux-*-x86_64 \
			Linux-*-i386   \
			Linux-*-arm*   \
			SunOS-*-i386 SunOS-*-x86_64

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest
SSP_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH:C/arm.*/arm/} == "arm"
PLIST_SUBST+=		VGCONF_ARCH_PRI=arm
.endif

.if ${MACHINE_ARCH} == "i386"
PLIST_SUBST+=		VGCONF_ARCH_PRI=x86
.endif

.if ${MACHINE_ARCH} == "x86_64"
PLIST_SUBST+=		VGCONF_ARCH_PRI=amd64
#PLIST_SUBST+=		VGCONF_ARCH_SEC=x86
CONFIGURE_ARGS+=	--enable-only64bit
.endif

.include "../../mk/bsd.pkg.mk"
