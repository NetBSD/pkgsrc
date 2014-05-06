# $NetBSD: Makefile,v 1.8 2014/05/06 13:58:03 ryoon Exp $

MOZ_BRANCH=		24.5.0
MOZ_BRANCH_MINOR=	esr
MOZ_VER=		${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
DISTNAME=		firefox-${MOZ_VER}.source
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=firefox/releases/${MOZ_VER}/source/}
#MASTER_SITES+=		${MASTER_SITE_MOZILLA:=firefox/releases/${MOZ_VER}/source/}
EXTRACT_SUFX=		.tar.bz2

PKGNAME=	xulrunner24-${MOZ_BRANCH}${MOZ_BRANCH_MINOR:S/esr//:S/b/beta/}
CATEGORIES=	devel www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment
LICENSE=	mpl-1.1

WRKSRC=		${WRKDIR}/mozilla-esr24

DISTINFO_FILE=	${.CURDIR}/../../www/firefox24/distinfo
PATCHDIR=	${.CURDIR}/../../www/firefox24/patches

CHECK_PORTABILITY_SKIP+=	js/src/tests/update-test262.sh

MOZILLA_DIR=	# empty

PKGCONFIG_OVERRIDE+=	xulrunner24/installer/libxul-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/libxul.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-gtkmozembed-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-gtkmozembed.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-js.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-nspr.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-nss.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner24/installer/mozilla-plugin.pc.in

CONFIGURE_ARGS+=	--enable-application=xulrunner
CONFIGURE_ARGS+=	--enable-libxul

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner24

MAKE_ENV+=		FREEBL_NO_DEPEND=0

# workround for link of xulrunner-bin etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/xulrunner24 ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

CHECK_INTERPRETER_SKIP+=lib/xulrunner24-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=lib/xulrunner24-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=lib/xulrunner24-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=lib/xulrunner24-sdk/sdk/bin/xpt.py

.include "../../www/firefox24/mozilla-common.mk"
.include "../../www/firefox24/options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	mkdir ${WRKSRC}/js/src/.deps

post-install:
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner24/libxpcomglue.a
	ln -s sdk/lib/libxpcomglue.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner24/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner24/libxpcomglue_s.a
	ln -s sdk/lib/libxpcomglue_s.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner24/libxpcomglue_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner24/libunicharutil_external_s.a
	ln -s sdk/lib/libunicharutil_external_s.a 			\
	  ${DESTDIR}${PREFIX}/lib/xulrunner24/libunicharutil_external_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner24/libmozglue.a
	ln -s sdk/lib/libmozglue.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner24/libmozglue.a
	${TOUCH} ${TOUCH_FLAGS} ${DESTDIR}${PREFIX}/include/xulrunner24/mozilla/throw_gcc.h

.include "../../mk/bsd.pkg.mk"
