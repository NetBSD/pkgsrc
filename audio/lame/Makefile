# $NetBSD: Makefile,v 1.54 2006/08/27 02:25:49 ben Exp $
#

DISTNAME=	lame-${VERS}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/} \
		http://hive.me.gu.edu.au/not_lame/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://lame.sourceforge.net/
COMMENT=	Fast, high quality MP3 encoder

VERS=		3.96.1

LICENSE=	lame-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-vorbis

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

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

.if (${MACHINE_ARCH} == "i386" && ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin")
BUILD_DEPENDS+=		nasm>=0.98:../../devel/nasm
CONFIGURE_ARGS+=	--enable-nasm
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
