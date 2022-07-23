# $NetBSD: Makefile,v 1.67 2022/07/23 23:02:14 wiz Exp $

PKGNAME=	${DISTNAME:C/[^[:alnum:]]*//}
PKGREVISION=	1
COMMENT=	MPEG layer 1, 2, and 3 audio player

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in libout123.pc.in libsyn123.pc.in

MPG123_BUILDING_BASE=	# empty

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	coreaudio oss sun alsa

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "SunOS"
MPG123_DEFAULT_MODULE=	sun
PLIST.sun=		yes
.elif ${OPSYS} == "Darwin"
MPG123_DEFAULT_MODULE=	coreaudio
PLIST.coreaudio=	yes
.elif ${OPSYS} == "Linux"
MPG123_DEFAULT_MODULE=	alsa,oss
MPG123_TRY_MODULES=	pulse,jack,alsa,oss
PLIST.alsa=		yes
PLIST.oss=		yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MPG123_DEFAULT_MODULE=	oss
PLIST.oss=		yes
.endif

.if !empty(PLIST.oss)
.include "../../mk/oss.buildlink3.mk"
LIBS+=		${LIBOSSAUDIO}
CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CPPFLAGS+=	-DDEVOSSSOUND="\"${DEVOSSSOUND}\""
.endif

# MPG123_MODULE is not finally set yet, to avoid NOT_FOR_PLATFORM triggers
.include "Makefile.common"

.include "options.mk"
.include "../../mk/bsd.pkg.mk"

# now we can set the default module
MPG123_MODULE=	${MPG123_DEFAULT_MODULE}
