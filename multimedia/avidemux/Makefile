# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:45 jlam Exp $
#

DISTNAME=	avidemux-2.0.18
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://fixounet.free.fr/avidemux/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://fixounet.free.fr/avidemux/
COMMENT=	Graphical video editing program

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

CFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"
LDFLAGS+=		${LIBOSSAUDIO}

CONFIGURE_ARGS+=	--disable-warnings

.include "../../mk/bsd.prefs.mk"

.if empty(USE_MMX:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--disable-mmx

post-configure:
	${MV} ${WRKSRC}/adm_lavcodec/config.mak \
		${WRKSRC}/adm_lavcodec/config.mak.in
	${SED} -e 's/TARGET_MMX=yes/TARGET_MMX=no/g' \
		< ${WRKSRC}/adm_lavcodec/config.mak.in \
		> ${WRKSRC}/adm_lavcodec/config.mak
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avidemux/avidemux2 ${PREFIX}/bin/avidemux

.include "../../audio/lame/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../multimedia/mjpegtools/buildlink2.mk"
.include "../../multimedia/xvidcore/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

CFLAGS+=	-O2	# -O3 won't work properly (according to authors)
