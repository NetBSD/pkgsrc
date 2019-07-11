# $NetBSD: Makefile,v 1.83 2019/07/11 11:20:06 sevan Exp $

DISTNAME=	lame-3.100
CATEGORIES=	audio
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lame.sourceforge.net/
COMMENT=	Fast, high quality MP3 encoder
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_FEATURES+=		strnlen

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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
