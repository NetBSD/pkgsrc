# $NetBSD: Makefile,v 1.20 2002/08/28 06:49:34 jlam Exp $
#

VERS=		3.92
DISTNAME=	lame-${VERS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lame/} \
		http://hive.me.gu.edu.au/not_lame/ \
		http://telia.dl.sourceforge.net/lame/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.mp3dev.org/mp3/
COMMENT=	Fast, high quality MP3 encoder

LICENSE=	fee-based-commercial-use

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-vorbis

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK)
.  include "../../x11/gtk/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--enable-analyzer=no
.endif

.if (${MACHINE_ARCH} == "alpha")
DEPENDS+=	libffm-[0-9]*:../../math/libffm
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
