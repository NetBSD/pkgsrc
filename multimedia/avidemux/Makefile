# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:01 tv Exp $
#

DISTNAME=	avidemux-2.0.18
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://fixounet.free.fr/avidemux/
COMMENT=	Graphical video editing program

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

CFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"
LDFLAGS+=		${LIBOSSAUDIO}

CONFIGURE_ARGS+=	--disable-warnings

BUILDLINK_TRANSFORM+=   rm:-O3

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_ARCH:Mi386)
BUILD_DEFS+=		USE_MMX

.  if empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--disable-mmx

post-configure:
	${MV} ${WRKSRC}/adm_lavcodec/config.mak \
		${WRKSRC}/adm_lavcodec/config.mak.in
	${SED} -e 's/TARGET_MMX=yes/TARGET_MMX=no/g' \
		< ${WRKSRC}/adm_lavcodec/config.mak.in \
		> ${WRKSRC}/adm_lavcodec/config.mak
.  endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avidemux/avidemux2 ${PREFIX}/bin/avidemux

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
