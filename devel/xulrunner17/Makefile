# $NetBSD: Makefile,v 1.22 2013/11/25 12:00:47 wiz Exp $

.include "dist.mk"
PKGNAME=	xulrunner17-${MOZ_BRANCH}${MOZ_BRANCH_MINOR:S/esr//}
PKGREVISION=	1
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

ALL_ENV+=		MOZILLA_PKG_NAME=xulrunner17

MAKE_ENV+=		FREEBL_NO_DEPEND=0

INSTALLATION_DIRS=	lib/pkgconfig

# workround for link of xulrunner-bin etc.
LDFLAGS+=		-Wl,-rpath,${PREFIX}/lib/xulrunner17 ${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "mozilla-common.mk"
.include "options.mk"

PLIST_VARS+=	sps webrtc vorbis tremor

.if !empty(MACHINE_PLATFORM:S/i386/x86/:MLinux-*-x86*) || ${OPSYS} == "Darwin"
PLIST.sps=	yes
.endif
.if ${OPSYS} == "Linux" || ${OPSYS} == "Darwin"
PLIST.webrtc=	yes
.endif

.if !empty(MACHINE_PLATFORM:MLinux-*-arm*) || ${OPSYS} == "DragonFly" \
    || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
PLIST.tremor=	yes
.else
PLIST.vorbis=	yes
.endif

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf

post-install:
	# XXX fix the pkg-config files instead
	mkdir ${DESTDIR}${PREFIX}/lib/xulrunner17-sdk/sdk/lib
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner17/libxpcomglue.a
	ln -s ${PREFIX}/lib/xulrunner17-sdk/sdk/lib/libxpcomglue.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner17/libxpcomglue.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner17/libxpcomglue_s.a
	ln -s ${PREFIX}/lib/xulrunner17-sdk/sdk/lib/libxpcomglue_s.a	\
	  ${DESTDIR}${PREFIX}/lib/xulrunner17/libxpcomglue_s.a
	rm -f ${DESTDIR}${PREFIX}/lib/xulrunner17/libunicharutil_external_s.a
	ln -s ${PREFIX}/lib/xulrunner17-sdk/sdk/lib/libunicharutil_external_s.a \
	  ${DESTDIR}${PREFIX}/lib/xulrunner17/libunicharutil_external_s.a
	${TOUCH} ${TOUCH_FLAGS} ${DESTDIR}${PREFIX}/include/xulrunner17/mozilla/throw_gcc.h
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/lib/xulrunner17-sdk/sdk/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dist/sdk/bin/xpt.py			\
	  ${DESTDIR}${PREFIX}/lib/xulrunner17-sdk/sdk/bin
	${INSTALL_LIB} ${WRKSRC}/mozglue/build/libmozglue.a		\
		${DESTDIR}${PREFIX}/lib/xulrunner17
	${INSTALL_LIB} ${WRKSRC}/mozglue/build/libmozglue.a		\
		${DESTDIR}${PREFIX}/lib/xulrunner17-sdk/sdk/lib
	ln -s ${PREFIX}/lib/xulrunner17/lib \
	  ${DESTDIR}${PREFIX}/lib/xulrunner17-sdk/lib

.include "../../mk/bsd.pkg.mk"
