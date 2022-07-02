# $NetBSD: options.mk,v 1.3 2022/07/02 19:46:21 tsutsui Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.PC6001VX
PKG_SUPPORTED_OPTIONS=	debug ffmpeg manual sdl2

# debug enables for debug monitor support, which can be disabled
# for low performance machines.
PKG_SUGGESTED_OPTIONS+=	debug
# ffmpeg is required for video capture support.
PKG_SUGGESTED_OPTIONS+=	ffmpeg
# SDL2 is required for joystick support.
PKG_SUGGESTED_OPTIONS+=	sdl2

# Generate README.html from README.adoc using asciidoc and source-highlight.
PKG_SUGGESTED_OPTIONS+=	manual

PLIST_VARS+=		manual

.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mdebug)
QMAKE_ARGS+=	"DEFINES+=NOMONITOR"
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
.include "../../multimedia/ffmpeg5/buildlink3.mk"
.else
QMAKE_ARGS+=	"DEFINES+=NOAVI"
.endif

.if !empty(PKG_OPTIONS:Msdl2)
.include "../../devel/SDL2/buildlink3.mk"
.else
QMAKE_ARGS+=	"DEFINES+=NOJOYSTICK"
.endif

.if !empty(PKG_OPTIONS:Mmanual)
PLIST.manual=	yes

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
BUILD_DEPENDS+=	source-highlight-[0-9]*:../../textproc/source-highlight

INSTALLATION_DIRS+=	share/doc/PC6001VX

post-build:
	cd ${WRKSRC} && asciidoc -o README.html README.adoc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.html \
	    ${DESTDIR}${PREFIX}/share/doc/PC6001VX
.endif
