# $NetBSD: Makefile,v 1.15 2001/07/31 14:23:01 drochner Exp $
#

VERS=		3.89
DISTNAME=	lame${VERS}beta
PKGNAME=	lame-${VERS}
WRKSRC=		${WRKDIR}/lame-${VERS}
CATEGORIES=	audio
MASTER_SITES=	ftp://lame.sourceforge.net/pub/lame/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.mp3dev.org/mp3/
COMMENT=	Fast, high quality MP3 encoder

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LICENSE=	fee-based-commercial-use

CONFIGURE_ARGS+=	--without-vorbis

.include "../../mk/bsd.prefs.mk"

.if defined(LAME_USE_GTK)
DEPENDS=		gtk+-1.2.*:../../x11/gtk
.else
CONFIGURE_ARGS+=	--enable-analyzer=no
.endif

.if (${MACHINE_ARCH} == "alpha")
DEPENDS+=	libffm-*:../../math/libffm
# double is faster than float on Alpha
CFLAGS+=	-O2 -Wall -fomit-frame-pointer -ffast-math -funroll-loops \
		-mfp-regs -fschedule-insns -fschedule-insns2 		  \
		-finline-functions -DFLOAT=double
.endif

.include "../../mk/bsd.pkg.mk"
