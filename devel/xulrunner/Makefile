# $NetBSD: Makefile,v 1.105 2013/05/19 08:47:41 ryoon Exp $

.include "dist.mk"
PKGNAME=	xulrunner-${MOZ_BRANCH}${MOZ_BRANCH_MINOR:S/esr//}
CATEGORIES=	devel www

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment
LICENSE=	mpl-1.1

BROKEN=		prefs and chrome:// load problem.

MOZILLA_DIR=	# empty

PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding.pc.in
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

MAKE_ENV+=		FREEBL_NO_DEPEND=0

# workround for link of xulrunner-bin etc.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/xulrunner ${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.SunOS+=		-lm

.include "mozilla-common.mk"
.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	mkdir ${WRKSRC}/js/src/.deps

post-install:
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	ln -s sdk/lib/libxpcomglue.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	ln -s sdk/lib/libxpcomglue_s.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libxpcomglue_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libunicharutil_external_s.a
	ln -s sdk/lib/libunicharutil_external_s.a 			\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libunicharutil_external_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner/libmozglue.a
	ln -s sdk/lib/libmozglue.a 					\
	  ${DESTDIR}${PREFIX}/lib/xulrunner/libmozglue.a
	${TOUCH} ${TOUCH_FLAGS} ${DESTDIR}${PREFIX}/include/xulrunner/mozilla/throw_gcc.h

.include "../../mk/bsd.pkg.mk"
