# $NetBSD: Makefile,v 1.29 2018/08/22 09:46:30 wiz Exp $

TORBVER=	6.0.8

DISTNAME=	v6.0.8-esr45.6.0
PKGNAME=	tor-browser-${TORBVER}
PKGREVISION=	14
CATEGORIES=	www
# Use OpenBSD distfile
MASTER_SITES=	${MASTER_SITE_OPENBSD:=distfiles/tor-browser/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.torproject.org/projects/torbrowser.html.en
COMMENT=	Tor Browser based on Firefox
LICENSE=	mpl-1.1

# A name of OpenBSD Ports distfile does not have 'tor-browser' inside.
DIST_SUBDIR=	tor-browser

EXTRACT_USING=	bsdtar
WRKSRC=		${WRKDIR}/${DISTNAME:S/v/torb-/}

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
CONFIGURE_ARGS+=        --enable-pie
CONFIGURE_ARGS+=        --enable-tor-data-in-home-dir
CFLAGS+=		-DTOR_BROWSER_DATA_IN_HOME_DIR=1
CFLAGS+=		-DTOR_BROWSER_DATA_OUTSIDE_APP_DIR=1
CFLAGS+=		-fPIC

# Avoid build failure from security/manager/ssl/src/nsNSSCallbacks.cpp:601
CFLAGS+=	-fpermissive

# workaround for link of libxul.so etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/tor-browser ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

ALL_ENV+=		MOZILLA_PKG_NAME=tor-browser

NOT_PAX_MPROTECT_SAFE+=	lib/tor-browser/firefox
NOT_PAX_MPROTECT_SAFE+=	lib/tor-browser/firefox-bin

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections

LDFLAGS.DragonFly=	-lplc4 -lnspr4
LDFLAGS.FreeBSD=	-lplc4 -lnspr4
LDFLAGS.Linux=		-lnspr4

.include "../../www/firefox45/mozilla-common.mk"
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

post-extract:
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf

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
