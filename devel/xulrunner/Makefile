# $NetBSD: Makefile,v 1.2 2009/08/05 06:10:31 tnn Exp $
#

DISTNAME=	xulrunner-${XULRUNNER_VER}-source
PKGNAME=	${DISTNAME:S/-source//}
XULRUNNER_VER=	1.9.1
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=xulrunner/releases/${XULRUNNER_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment

WRKSRC=		${WRKDIR}/mozilla-1.9.1
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl gmake autoconf213
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-js.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nspr.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nss.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-plugin.pc.in

PRIVILEGED_STAGES=	clean

CONFIG_GUESS_OVERRIDE=	build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	nsprpub/build/autoconf/config.guess
CONFIG_SUB_OVERRIDE=	build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	nsprpub/build/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=xulrunner
CONFIGURE_ARGS+=	--enable-libxul
CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-gnomeui
CONFIGURE_ARGS+=	--disable-dbus --disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg --enable-mathml
CONFIGURE_ARGS+=	--enable-system-cairo --enable-system-lcms
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib --with-system-bz2
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC}/nsprpub && autoconf


# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

post-install:
	# XXX fix the pkg-config files instead
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	ln -s ${PREFIX}/lib/xulrunner-sdk/sdk/lib/libxpcomglue.a \
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	ln -s ${PREFIX}/lib/xulrunner-sdk/sdk/lib/libxpcomglue_s.a \
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	cd ${WRKSRC}/dist/include && \
	  ${INSTALL_DATA} `find js -name "*.h" -print` js/jsproto.tbl \
	  mozilla-config.h \
	  commandhandler/nsICommandManager.h \
	  commandhandler/nsICommandParams.h \
	  content/nsISelectionController.h \
	  content/nsISelectionDisplay.h \
	  docshell/nsIDocShell.h \
	  dom/nsIDOMNSEvent.h \
	  fastfind/nsITypeAheadFind.h \
	  gfx/gfxCore.h \
	  gfx/nsCoord.h \
	  gfx/nsMargin.h \
	  gtkembedmoz/gtkmozembed.h \
	  gtkembedmoz/gtkmozembed_glue.cpp \
	  gtkembedmoz/gtkmozembed_internal.h \
	  layout/nsIPrintProgressParams.h \
	  webbrwsr/nsIPrintingPromptService.h \
	  widget/nsIPrintSettings.h \
	  xpcom/nsMathUtils.h \
	  ${DESTDIR}${PREFIX}/include/xulrunner/unstable

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
