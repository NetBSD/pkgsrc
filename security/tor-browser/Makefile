# $NetBSD: Makefile,v 1.57 2020/04/07 14:29:09 wiz Exp $

DISTNAME=	src-firefox-tor-browser-68.6.0esr-9.0-1-build2
PKGNAME=	tor-browser-9.0.7
CATEGORIES=	security www
MASTER_SITES=	https://dist.torproject.org/torbrowser/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
#DISTFILES=	${DISTNAME}${EXTRACT_SUFX} src-tor-launcher-0.2.20.5${EXTRACT_SUFX}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://www.torproject.org/projects/torbrowser.html.en
COMMENT=	Tor Browser based on Firefox
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

DEPENDS+=	tor-[0-9]*:../../net/tor

EXTRACT_USING=	bsdtar

# How to update this package:
#
# replace all patches with the one from the correspoding www/firefox${ESR_RELEASE}
# BUT keep patch-xpcom_io_TorFileUtils.cpp! (and if necessary patch-.mozconfig)
# make the patches apply
#
# when packaged up, read MESSAGE and test by visiting https://check.torproject.org

# Remove hardcoded build directory.
SUBST_CLASSES+=			fix-build-dir
SUBST_STAGE.fix-build-dir=	pre-configure
SUBST_FILES.fix-build-dir+=	.mozconfig
SUBST_SED.fix-build-dir+=	-e 's,mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-@CONFIG_GUESS@,,'

MOZILLA_DIR=	# empty

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-tor-browser-data-outside-app-dir
CONFIGURE_ARGS+=	--with-tor-browser-version=${PKGVERSION_NOREV}
CFLAGS+=		-DTOR_BROWSER_DATA_IN_HOME_DIR=1
CFLAGS+=		-DTOR_BROWSER_DATA_OUTSIDE_APP_DIR=1
CFLAGS+=		-fPIC

# workaround for link of libxul.so etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.DragonFly+=	-lplc4 -lnspr4
LDFLAGS.FreeBSD+=	-lplc4 -lnspr4
LDFLAGS.Linux+=		-lnspr4
LDFLAGS.SunOS+=		-lm

ALL_ENV+=		MOZ_APP_NAME=${PKGBASE}

NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/tor-browser
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/tor-browser-bin

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections

.include "../../www/firefox68/mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${PKGBASE}/chrome/toolkit/content/global/buildconfig.html

MOZILLA=	${PKGBASE}
MOZILLA_ICON=	${WRKSRC}/browser/branding/official/default48.png
MOZILLA_NAME=	TorBrowser

post-extract:
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c
#	mv ${WRKDIR}/tor-launcher* ${WRKSRC}/browser/extensions/tor-launcher

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars
	cd ${WRKSRC}/js/src && autoconf

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${ECHO} '${PREFIX}/lib/tor-browser/tor-browser-bin "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
