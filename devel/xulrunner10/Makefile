# $NetBSD: Makefile,v 1.40 2016/03/05 11:27:46 jperkin Exp $

.include "dist.mk"
PKGNAME=	xulrunner10-${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
PKGREVISION=	28
CATEGORIES=	devel www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment
LICENSE=	mpl-1.1

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

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner10

MAKE_ENV+=		FREEBL_NO_DEPEND=0

# workround for link of xulrunner-bin etc.
LDFLAGS+=		-Wl,-rpath,${PREFIX}/lib/xulrunner10

.include "mozilla-common.mk"
.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC}/nsprpub && autoconf

post-install:
	# XXX fix the pkg-config files instead
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner10/libxpcomglue.a
	ln -s ${PREFIX}/lib/xulrunner10-sdk/sdk/lib/libxpcomglue.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner10/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner10/libxpcomglue_s.a
	ln -s ${PREFIX}/lib/xulrunner10-sdk/sdk/lib/libxpcomglue_s.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner10/libxpcomglue_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner10/libunicharutil_external_s.a
	ln -s ${PREFIX}/lib/xulrunner10-sdk/sdk/lib/libunicharutil_external_s.a \
	  ${DESTDIR}${PREFIX}/lib/xulrunner10/libunicharutil_external_s.a
	${TOUCH} ${TOUCH_FLAGS} ${DESTDIR}${PREFIX}/include/xulrunner10/mozilla/throw_gcc.h
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/lib/xulrunner10-sdk/sdk/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dist/sdk/bin/xpt.py			\
	  ${DESTDIR}${PREFIX}/lib/xulrunner10-sdk/sdk/bin

.include "../../mk/bsd.pkg.mk"
