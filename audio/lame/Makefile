# $NetBSD: Makefile,v 1.33 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=	lame-${VERS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/} \
		http://hive.me.gu.edu.au/not_lame/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.mp3dev.org/mp3/
COMMENT=	Fast, high quality MP3 encoder

VERS=		3.95.1

LICENSE=	fee-based-commercial-use

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-vorbis

LDFLAGS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK)
CONFIGURE_ENV+=		GTK_CONFIG=${BUILDLINK_PREFIX.gtk}/bin/gtk-config
.  include "../../x11/gtk/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--disable-analyzer
.endif

.if ${MACHINE_ARCH} == "alpha"
.  include "../../math/libffm/buildlink2.mk"
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
