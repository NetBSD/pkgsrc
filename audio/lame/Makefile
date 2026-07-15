# $NetBSD: Makefile,v 1.98 2026/07/15 07:09:51 adam Exp $

DISTNAME=	lame-4.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lame.sourceforge.io/
COMMENT=	Fast, high quality MP3 encoder
LICENSE=	gnu-lgpl-v2

USE_FEATURES+=		strnlen
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
# Fix for faulty detection of iconv.
CONFIGURE_ENV.Darwin=	am_cv_func_iconv_works=yes

LDFLAGS.SunOS+=		-lm
LDFLAGS.NetBSD+=	-ltermcap

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-incompatible-pointer-types

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "alpha"
.  include "../../math/libffm/buildlink3.mk"
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double -DFLOAT_MAX=DBL_MAX
.endif

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
TOOL_DEPENDS+=		nasm>=0.98:../../devel/nasm
CONFIGURE_ARGS+=	--enable-nasm
.endif

.include "../../audio/mpg123/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
