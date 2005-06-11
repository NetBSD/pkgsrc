# $NetBSD: Makefile,v 1.17 2005/06/11 16:57:29 wiz Exp $
#

DISTNAME=	avidemux-2.0.40
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/avidemux/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fixounet.free.fr/avidemux/
COMMENT=	Graphical video editing program

GCC_REQD=		3.0
GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

CPPFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
LDFLAGS+=		${LIBOSSAUDIO}
CONFIGURE_ENV+=		ac_cv_path_ART_CONFIG=no
CONFIGURE_ARGS+=	--disable-faad # Dolby doesn't allow binary distribution

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.avidemux
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS=	mmx
.endif

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mmmx)
CONFIGURE_ARGS+=	--disable-mmx

post-configure:
	${MV} ${WRKSRC}/adm_lavcodec/config.mak \
		${WRKSRC}/adm_lavcodec/config.mak.in
	${SED} -e 's/TARGET_MMX=yes/TARGET_MMX=no/g' \
		< ${WRKSRC}/adm_lavcodec/config.mak.in \
		> ${WRKSRC}/adm_lavcodec/config.mak
.endif

.include "../../audio/faac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/mjpegtools/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
