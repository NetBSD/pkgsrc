# $NetBSD: Makefile,v 1.72 2012/09/12 00:24:41 asau Exp $

DISTNAME=	lame-3.99.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lame.sourceforge.net/
COMMENT=	Fast, high quality MP3 encoder
LICENSE=	lame-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

LDFLAGS.SunOS+=		-lm

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "alpha"
.  include "../../math/libffm/buildlink3.mk"
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double -DFLOAT_MAX=DBL_MAX
.endif

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin" && ${OPSYS} != "Interix"
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
CONFIGURE_ARGS+=	--enable-nasm
.endif

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ENV+=		ac_cv_header_xmmintrin_h=no
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
