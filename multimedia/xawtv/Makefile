# $NetBSD: Makefile,v 1.10 2005/06/10 18:26:36 wiz Exp $
#

DISTNAME=	xawtv_3.90
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://bytesex.org/xawtv/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://bytesex.org/xawtv/
COMMENT=	TV application for Brooktree 848 compatible cards

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_PERL5=		build

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

PKG_OPTIONS_VAR=	PKG_OPTIONS.xawtv
PKG_SUPPORTED_OPTIONS=	mmx

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.prefs.mk"

.if !empty(PKG_OPTIONS:Mmmx)
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-mmx
.endif
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
