# $NetBSD: Makefile,v 1.57.8.1 2019/08/09 13:11:04 bsiegert Exp $

PKGNAME=	${DISTNAME:C/[^[:alnum:]]*//}
COMMENT=	MPEG layer 1, 2, and 3 audio player

PKGCONFIG_OVERRIDE+=	libmpg123.pc.in

MAKE_ENV+=		MPG123_PROGRAM=mpg123
MAKE_ENV+=		EXTRA_INSTALL_TARGETS="install-exec-am install-data-am"

MPG123_BUILDING_BASE=	# empty

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	coreaudio oss sun

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "SunOS"
MPG123_DEFAULT_MODULE=	sun
PLIST.sun=		yes
.elif ${OPSYS} == "Darwin"
MPG123_DEFAULT_MODULE=	coreaudio
PLIST.coreaudio=	yes
.else
MPG123_DEFAULT_MODULE=	oss
PLIST.oss=		yes
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
MPG123_MODULE=		${MPG123_DEFAULT_MODULE}
