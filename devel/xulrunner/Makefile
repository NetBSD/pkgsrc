# $NetBSD: Makefile,v 1.37 2010/02/17 18:32:18 tnn Exp $

.include "dist.mk"
PKGNAME=	xulrunner-${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
CATEGORIES=	devel www

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment
LICENSE=	mpl-1.1

MOZILLA_DIR=	# empty

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

CONFIGURE_ARGS+=	--enable-application=xulrunner
CONFIGURE_ARGS+=	--enable-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner

.include "mozilla-common.mk"
.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC}/nsprpub && autoconf

INCLUDE_SUBDIRS=\
	caps chardet commandhandler content cookie docshell dom		\
	downloads embedcomponents exthandler fastfind find gfx		\
	gtkembedmoz htmlparser imglib2 intl java js layout libreg	\
	locale loginmgr mimetype necko nkcache nspr oji pipboot pipnss	\
	places pref profdirserviceprovider rdf shistory spellchecker	\
	string thebes toolkitcomps uconv uriloader webbrowserpersist	\
	webbrwsr webshell widget windowwatcher xpcom xpconnect xulapp	\
	plugin liveconnect

post-install:
	# XXX fix the pkg-config files instead
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	ln -s ${PREFIX}/lib/xulrunner-sdk/sdk/lib/libxpcomglue.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	ln -s ${PREFIX}/lib/xulrunner-sdk/sdk/lib/libxpcomglue_s.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	${INSTALL_LIB} ${WRKSRC}/dist/lib/libunicharutil_external_s.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner
.for dir in ${INCLUDE_SUBDIRS}
	cd ${WRKSRC}/dist/include &&					\
	  ${INSTALL_DATA} `find ${dir} -name "*.h" -print`		\
	  ${DESTDIR}${PREFIX}/include/xulrunner/unstable
.endfor
	cd ${WRKSRC}/dist/include && ${INSTALL_DATA}			\
	  js/jsproto.tbl mozilla-config.h gtkembedmoz/gtkmozembed_glue.cpp \
	  ${DESTDIR}${PREFIX}/include/xulrunner/unstable
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/xulrunner/unstable/obsolete
	cd ${WRKSRC}/dist/include/nspr/obsolete && ${INSTALL_DATA} protypes.h \
	  ${DESTDIR}${PREFIX}/include/xulrunner/unstable/obsolete

.include "../../mk/bsd.pkg.mk"
