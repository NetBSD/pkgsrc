# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:28 wiz Exp $
#

DISTNAME=	xawtv-3.95
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.bytesex.org/releases/xawtv/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://linux.bytesex.org/xawtv/
COMMENT=	TV application for Brooktree 848 compatible cards

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake perl

CONFIGURE_ARGS+=	--disable-aalib
CONFIGURE_ARGS+=	--disable-motif

LDFLAGS+=		${LIBOSSAUDIO}

SUBST_CLASSES+=		devoss
SUBST_MESSAGE.devoss=	"Fixing path to OSS audio device."
SUBST_STAGE.devoss=	pre-configure
SUBST_FILES.devoss=	console/record.c libng/devices.c x11/pia.c
SUBST_FILES.devoss+=	man/motv.1 man/record.1 man/streamer.1 man/xawtv.1
SUBST_FILES.devoss+=	man/es/streamer.1 man/es/xawtv.1 man/fr/xawtv.1
SUBST_SED.devoss=	-e 's|/dev/dsp|${DEVOSSAUDIO}|g'

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xawtv
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--enable-mmx
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
