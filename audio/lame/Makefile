# $NetBSD: Makefile,v 1.44 2005/02/03 17:54:50 reed Exp $
#

DISTNAME=	lame-${VERS}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/} \
		http://hive.me.gu.edu.au/not_lame/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://lame.sourceforge.net/
COMMENT=	Fast, high quality MP3 encoder

VERS=		3.96.1

LICENSE=	lame-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-vorbis

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

LDFLAGS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK)
CONFIGURE_ENV+=		GTK_CONFIG=${BUILDLINK_PREFIX.gtk}/bin/gtk-config
.  include "../../x11/gtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-analyzer
.endif

.if ${MACHINE_ARCH} == "alpha"
.  include "../../math/libffm/buildlink3.mk"
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double -DFLOAT_MAX=DBL_MAX
.endif

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
