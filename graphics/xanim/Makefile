# $NetBSD: Makefile,v 1.30 2002/10/26 13:11:37 bouyer Exp $

DISTNAME=	xanim2801
PKGNAME=	xanim-2.80.1
PKGREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://xanim.va.pubnix.com/\
		ftp://xanim.va.pubnix.com/modules/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/ \
		ftp://ftp.ut.ee/pub/graphics/xanim/modules/ \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/ \
		ftp://ftp.ba-stuttgart.de/Mirrors/xanim/modules/ \
		http://smurfland.cit.buffalo.edu/xanim/files/ \
		http://smurfland.cit.buffalo.edu/xanim/files/modules/
DISTFILES=	${EXTRACT_ONLY} ${CODEC_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xanim.va.pubnix.com/
COMMENT=	play most popular animation formats and show pictures

EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

.include "Makefile.codecs"

USE_BUILDLINK2=	YES
USE_X11BASE=	YES
USE_IMAKE=	YES

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=		${XANIM_AUDIO.${OPSYS}}
XANIM_AUDIO.Linux=	XA_AUDIO_DEFS="-DXA_LINUX_AUDIO"		\
			XA_AUDIO_LIBS="-lc"

.if defined(USE_OSS)
XANIM_AUDIO.NetBSD=	XA_AUDIO_DEFS="-DXA_LINUX_AUDIO"		\
			XA_AUDIO_LIBS="${LIBOSSAUDIO}"
.else
XANIM_AUDIO.NetBSD=	XA_AUDIO_DEFS="-DXA_NetBSD_AUDIO"
.endif

XANIM_AUDIO.SunOS=	XA_AUDIO_DEFS="-DXA_SPARC_AUDIO -DSVR4 -DXA_SELECT"

post-extract:
	@${LN} -s docs/xanim.man ${WRKSRC}
	@${MKDIR} ${WRKSRC}/mods
.if defined(CODEC_FILES) && !empty(CODEC_FILES)
	@for file in ${CODEC_FILES}; do					\
		${CP} ${DISTDIR}/$$file ${WRKSRC}/mods;			\
		${GUNZIP_CMD} ${WRKSRC}/mods/$$file;			\
	done
.endif

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
