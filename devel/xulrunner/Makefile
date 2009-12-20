# $NetBSD: Makefile,v 1.23.2.2 2009/12/20 19:41:08 spz Exp $
#

DISTNAME=	firefox-${FIREFOX_VER}.source
PKGNAME=	${DISTNAME:S/firefox/xulrunner/:S/3.5/1.9.1/:S/.source//}
FIREFOX_VER=	3.5.6
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=firefox/releases/${FIREFOX_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment

WRKSRC=		${WRKDIR}/mozilla-1.9.1
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
