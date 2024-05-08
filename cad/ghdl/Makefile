# $NetBSD: Makefile,v 1.19 2024/05/08 11:37:51 wiz Exp $

DISTNAME=	ghdl-3.0.0
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=ghdl/}
GITHUB_PROJECT=	ghdl
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://ghdl.github.io/ghdl/
COMMENT=	Open-source simulator/compiler/analyzer for the VHDL
LICENSE=	gnu-gpl-v2

BROKEN=		"Does not support llvm 17."

USE_TOOLS+=		bash:run gmake

USE_LANGUAGES+=		c c++ # ada

# lang/gcc10-aux does not support RELRO
# and this package should use same condition.
RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no

REPLACE_BASH=		scripts/vendors/*.sh
## This approach to use __time50() and __ctime50() is unavailable
## because Ada language would not accept symbols start with '_'.
#.include "../../mk/bsd.prefs.mk"
#.if ${OPSYS} == "NetBSD"
#SUBST_CLASSES+=	time
#SUBST_STAGE.time=	pre-configure
#SUBST_MESSAGE.time=	Use correct functions in time.h
#SUBST_FILES.time+=	src/grt/grt-vcd.adb
#SUBST_SED.time+=	-e 's/pragma Import (C, time);/pragma Import (C, __time50);/g'
#SUBST_SED.time+=	-e 's/pragma Import (C, ctime);/pragma Import (C, __ctime50);/g'
#.endif

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		GNATMAKE=${PREFIX}/gcc10-aux/bin/gnatmake
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-synth
CONFIGURE_ARGS+=	--enable-libghdl
# Select LLVM backend
CONFIGURE_ARGS+=	--with-llvm-config=${PREFIX}/bin/llvm-config

BUILDLINK_DEPMETHOD.clang=	build
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
# GNAT 8.1 or later is required for --enable-synth.
.include "../../lang/gcc10-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
