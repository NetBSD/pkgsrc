# $NetBSD: Makefile,v 1.4 2016/03/14 14:30:47 ryoon Exp $

TORBVER=	5.5.3

DISTNAME=	tor-browser-38.7.0esr-5.5-1
PKGNAME=	tor-browser-${TORBVER}
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.torproject.org/projects/torbrowser.html.en
COMMENT=	Tor Browser based on Firefox
LICENSE=	mpl-1.1

DEPENDS+=	tor-[0-9]*:../../net/tor

# Remove hardcoded build directory.
SUBST_CLASSES+=			fix-build-dir
SUBST_STAGE.fix-build-dir+=	pre-configure
SUBST_FILES.fix-build-dir+=	.mozconfig
SUBST_SED.fix-build-dir+=	-e 's,mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-@CONFIG_GUESS@,,'

MOZILLA_DIR=	# empty

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--disable-tor-browser-update
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--disable-gio
CONFIGURE_ARGS+=	--disable-dbus
CONFIGURE_ARGS+=	--disable-gnomeui
CONFIGURE_ARGS+=        --disable-libnotify

# Avoid build failure from security/manager/ssl/src/nsNSSCallbacks.cpp:601
CFLAGS+=	-fpermissive

# workround for link of libxul.so etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/tor-browser ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

ALL_ENV+=		MOZILLA_PKG_NAME=tor-browser

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections

LDFLAGS.DragonFly=	-lplc4 -lnspr4
LDFLAGS.FreeBSD=	-lplc4 -lnspr4
LDFLAGS.Linux=		-lnspr4

.include "../../www/firefox38/mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=lib/firefox-sdk/sdk/bin/xpt.py

MOZILLA=	tor-browser
MOZILLA_ICON=	${WRKSRC}/${OBJDIR}/dist/firefox/browser/chrome/icons/default/default48.png
MOZILLA_NAME=	TorBrowser

SUBST_CLASSES+=		sys-dic
SUBST_STAGE.sys-dic=	pre-configure
SUBST_MESSAGE.sys-dic=	Reference to system hunspell dictionaries.
SUBST_FILES.sys-dic=	extensions/spellcheck/hunspell/src/mozHunspell.cpp
SUBST_VARS.sys-dic=	PREFIX

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
# XXX Makefile is broken? When libxul is provided from devel/xulrunner,
# XXX please remove this.
	mkdir ${WRKSRC}/js/src/.deps

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
