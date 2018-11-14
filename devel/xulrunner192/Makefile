# $NetBSD: Makefile,v 1.65 2018/11/14 22:21:21 kleink Exp $

.include "dist.mk"
PKGNAME=	xulrunner192-${MOZ_BRANCH}${MOZ_BRANCH_MINOR}
PKGREVISION=	49
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
CONFIGURE_ARGS+=	--disable-ipc

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner192

MAKE_ENV+=		FREEBL_NO_DEPEND=0

SUBST_CLASSES+=			fix-paths2
SUBST_STAGE.fix-paths2=		pre-configure
SUBST_MESSAGE.fix-paths2=	Fixing absolute paths.
SUBST_FILES.fix-paths2=		${MOZILLA_DIR}xpcom/build/nsXPCOMPrivate.h
SUBST_FILES.fix-paths2+=	${MOZILLA_DIR}xulrunner/app/nsRegisterGREUnix.cpp
SUBST_FILES.fix-paths2+=	${MOZILLA_DIR}xulrunner/installer/Makefile.in
SUBST_SED.fix-paths2=           -e 's,/etc/gre.d,${PREFIX}/lib/xulrunner192/gre.d,g'

.include "../../devel/xulrunner192/mozilla-common.mk"
CONFIGURE_ARGS+=	--enable-chrome-format=jar
.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC}/nsprpub && autoconf

post-install:
	# XXX fix the pkg-config files instead
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner192/libxpcomglue.a
	ln -s ${PREFIX}/lib/xulrunner192-sdk/sdk/lib/libxpcomglue.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner192/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner192/libxpcomglue_s.a
	ln -s ${PREFIX}/lib/xulrunner192-sdk/sdk/lib/libxpcomglue_s.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner192/libxpcomglue_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner192/libunicharutil_external_s.a
	ln -s ${PREFIX}/lib/xulrunner192-sdk/sdk/lib/libunicharutil_external_s.a \
	  ${DESTDIR}${PREFIX}/lib/xulrunner192/libunicharutil_external_s.a

.include "../../mk/bsd.pkg.mk"
