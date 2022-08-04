# $NetBSD: Makefile,v 1.108 2022/08/04 15:07:14 nia Exp $
#
# How to update this package:
#
# replace all patches with the one from the correspoding www/firefox${ESR_RELEASE}
# compare e.g. the output of
# diff -r -I NetBSD . ../../www/firefox78
# BUT keep:
# patch-.mozconfig (if still necessary)
# patch-browser_app_profile_000-tor-browser.js
# patch-toolkit_moz.configure (second chunk)
# patch-xpcom_io_TorFileUtils.cpp
# make the patches apply
#
# when packaged up, read MESSAGE and test by visiting https://check.torproject.org
# and https://panopticlick.eff.org

DISTNAME=	src-firefox-tor-browser-78.15.0esr-10.5-1-build3
PKGNAME=	tor-browser-10.5.10
PKGREVISION=	5
CATEGORIES=	security www
MASTER_SITES=	https://dist.torproject.org/torbrowser/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	tor-browser-linux64-${PKGVERSION_NOREV}_en-US${EXTRACT_SUFX}
#DISTFILES+=	src-tor-launcher-0.2.30${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/projects/torbrowser.html.en
COMMENT=	Tor Browser based on Firefox
LICENSE=	mpl-1.1

UNLIMIT_RESOURCES+=	datasize virtualsize

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

# as of 10.5.10, 11.x is fine with python 3.10
PYTHON_VERSIONS_INCOMPATIBLE=	310

MOZILLA_DIR=	# empty

DEPENDS+=	tor-[0-9]*:../../net/tor
DEPENDS+=	tor-browser-https-everywhere>=2020.5.20:../../security/tor-browser-https-everywhere
DEPENDS+=	tor-browser-noscript>=11.0.32:../../security/tor-browser-noscript

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

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

# Workaround for https://bugs.llvm.org/show_bug.cgi?id=46366
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fexperimental-new-pass-manager

# Remove hardcoded build directory.
SUBST_CLASSES+=			fix-build-dir
SUBST_STAGE.fix-build-dir=	pre-configure
SUBST_FILES.fix-build-dir+=	.mozconfig
SUBST_SED.fix-build-dir+=	-e 's,mk_add_options MOZ_OBJDIR=@TOPSRCDIR@/obj-@CONFIG_GUESS@,,'

SUBST_CLASSES+=		fonts
SUBST_STAGE.fonts=	pre-configure
SUBST_FILES.fonts+=	tor-browser_en-US/Browser/TorBrowser/Data/fontconfig/fonts.conf
SUBST_SED.fonts+=	-e 's,<dir>fonts</dir>,<dir>${PREFIX}/lib/tor-browser/browser/fonts</dir>,'
SUBST_MESSAGE.fonts=	Fixing path to bundled fonts directory.

.include "../../mail/thunderbird/mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${PKGBASE}/chrome/toolkit/content/global/buildconfig.html

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

CKSUM_CRATES+=	third_party/rust/libc

# patch-third__party_rust_libc_src_unix_bsd_netbsdlike_netbsd_mod.rs
CKSUMS+=	a3540eab4dbc52e006e84e288bad17e1dae3865fea49020e0ed8b5a7724a9532
CKSUMS+=	5e58a2109f5eff0f497dfac150c161c1d517a2227b49e086da96c3d66522ac3a

CKSUM_CRATES+=	third_party/rust/getrandom

# patch-third__party_rust_getrandom_src_lib.rs
CKSUMS+=	0e52f6bde42d7bb05c297ce1c25b9879d61b28caba98f6226a152bff538db6c2
CKSUMS+=	394425b4ba03c21c494e64d993678f7014575b1e3d590b9ee452b5c2d83ec4ac

CKSUM_CRATES+=	third_party/rust/packed_simd

# patch-third__party_rust_packed__simd_src_lib.rs
CKSUMS+=	2924d414fe7d32bb5f0bb92596a5af654f934d92f81dc1fd9b1a6c580388e5bd
CKSUMS+=	99e70e436baa1d2080a46b38a146522fa6a8f2c60e1fa0a4d3aa125dc425734b

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

MOZILLA=	${PKGBASE}
MOZILLA_ICON=	${WRKSRC}/browser/branding/official/default48.png
MOZILLA_NAME=	TorBrowser

post-extract:
	mv ${WRKSRC}/gfx/ycbcr/yuv_row_arm.s ${WRKSRC}/gfx/ycbcr/yuv_row_arm.S
	mv ${WRKDIR}/tor-browser_en-US ${WRKSRC}
#	mv ${WRKDIR}/tor-launcher* ${WRKSRC}/browser/extensions/tor-launcher

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars
	# Do not fetch Rust Cargo file via network during build

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop
	${SED} -e 's|@PREFIX@|${PREFIX}|g'				\
	  < ${FILESDIR}/tor-browser.sh					\
	  > ${WRKDIR}/tor-browser.sh

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PREFIX}/lib/tor-browser/browser/fontconfig
INSTALLATION_DIRS+=	${PREFIX}/lib/tor-browser/browser/fonts

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tor-browser.sh \
		${DESTDIR}${PREFIX}/bin/tor-browser
	${INSTALL_DATA} ${WRKDIR}/desktop				\
		${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
		${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	${INSTALL_DATA} ${WRKSRC}/tor-browser_en-US/Browser/TorBrowser/Data/fontconfig/fonts.conf \
		${DESTDIR}${PREFIX}/lib/tor-browser/browser/fontconfig
	${INSTALL_DATA} ${WRKSRC}/tor-browser_en-US/Browser/fonts/* \
		${DESTDIR}${PREFIX}/lib/tor-browser/browser/fonts

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
