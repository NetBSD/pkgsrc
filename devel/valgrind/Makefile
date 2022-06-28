# $NetBSD: Makefile,v 1.36 2022/06/28 11:33:45 wiz Exp $
#

DISTNAME=		valgrind-3.17.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://sourceware.org/pub/valgrind/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://valgrind.org/
COMMENT=		Debugging and profiling tools
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	valgrind.pc.in
GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	Darwin-*-i386 Darwin-*-x86_64 \
			Linux-*-x86_64 \
			Linux-*-i386   \
			Linux-*-arm*   \
			SunOS-*-i386 SunOS-*-x86_64

USE_TOOLS+=		gmake perl:run
USE_LANGUAGES=		c c++
TEST_TARGET=		regtest
SSP_SUPPORTED=		no
REPLACE_PERL+=		callgrind/callgrind_annotate.in
REPLACE_PERL+=		callgrind/callgrind_control.in

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

# musl.supp was accidentally excluded from the valgrind-3.17.0
# tarball, so add it back.
post-extract:
	${CP} ${FILESDIR}/musl.supp ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
