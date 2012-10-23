# $NetBSD: Makefile,v 1.20 2012/10/23 10:24:09 wiz Exp $

DISTNAME=	xanim2920
PKGNAME=	xanim-2.92.0
PKGREVISION=	2
CATEGORIES=	multimedia x11
MASTER_SITES=	ftp://ftp.informatik.uni-hamburg.de/pub/soft/graphics/xanim/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/soft/graphics/xanim/modules/ \
		ftp://ftp.nstu.ru/pub/mirrors/xanim.va.pubnix.com/ \
		ftp://ftp.nstu.ru/pub/mirrors/xanim.va.pubnix.com/modules/
DISTFILES=	${EXTRACT_ONLY} ${CODEC_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Play a variety of simple animation formats and show pictures
HOMEPAGE=	http://xanim.polter.net/
LICENSE=	xanim-license

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "Makefile.codecs"

USE_IMAKE=	YES
USE_TOOLS+=	gunzip

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		${XANIM_AUDIO.${OPSYS}}
XANIM_AUDIO.Linux=	XA_AUDIO_DEFS="-DXA_LINUX_AUDIO"		\
			XA_AUDIO_LIBS="-lc"

PKG_OPTIONS_VAR=	PKG_OPTIONS.xanim
PKG_SUPPORTED_OPTIONS=	oss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Moss)
XANIM_AUDIO.NetBSD=	XA_AUDIO_DEFS="-DXA_LINUX_AUDIO"		\
			XA_AUDIO_LIBS="${LIBOSSAUDIO}"
.else
XANIM_AUDIO.NetBSD=	XA_AUDIO_DEFS="-DXA_NetBSD_AUDIO"
.endif

XANIM_AUDIO.SunOS=	XA_AUDIO_DEFS="-DXA_SPARC_AUDIO -DSVR4 -DXA_SELECT"

post-extract:
	${LN} -s docs/xanim.man ${WRKSRC}
	${MKDIR} ${WRKSRC}/mods
.if defined(CODEC_FILES) && !empty(CODEC_FILES)
	for file in ${CODEC_FILES}; do					\
		${CP} ${DISTDIR}/$$file ${WRKSRC}/mods;			\
		${GUNZIP_CMD} ${WRKSRC}/mods/$$file;			\
	done
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
