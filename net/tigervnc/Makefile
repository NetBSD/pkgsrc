# $NetBSD: Makefile,v 1.52 2022/08/08 16:47:34 adam Exp $

DISTNAME=		tigervnc-1.12.0
PKGNAME=		${DISTNAME}.1.20.13
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=TigerVNC/}
GITHUB_TAG=		v1.12.0
XORG_SERVER_FILE=	xorg-server-1.20.13
SITES.${XORG_SERVER_FILE}.tar.xz=	${MASTER_SITE_XORG:=xserver/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${XORG_SERVER_FILE}.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tigervnc.org/
COMMENT=	High-performance, platform-neutral VNC client/server
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	xorg-util-macros-[0-9]*:../../devel/xorg-util-macros
BUILD_DEPENDS+=	font-util-[0-9]*:../../fonts/font-util
BUILD_DEPENDS+=	tradcpp-[0-9]*:../../devel/tradcpp

DEPENDS+=	mcookie-[0-9]*:../../x11/mcookie
DEPENDS+=	xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

REPLACE_BASH+=	unix/vncserver/vncsession-start.in
REPLACE_PERL+=	unix/vncserver/vncserver.in

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool msgfmt msgmerge patch perl:run autoconf automake autoreconf pkg-config gmake bash:run
BUILD_DIRS=	. unix/xserver
INSTALL_DIRS=	. unix/xserver/hw/vnc
INSTALL_TARGET=	install

CMAKE_ARGS+=		CMAKE_INSTALL_SYSCONFDIR=${PKG_SYSCONFDIR}
# for reallocarray()
CPPFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

LDFLAGS+=	${BUILDLINK_LDADD.gettext}
LDFLAGS.SunOS+=	-lsocket -lnsl

CONFIGURE_ENV+=			ac_cv_path_RAWCPP="${PREFIX}/bin/tradcpp -Uunix"
OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
LIBTOOL_OVERRIDE=		unix/xserver/libtool

SUBST_CLASSES+=		hpath
SUBST_STAGE.hpath=	pre-configure
SUBST_MESSAGE.hpath=	fixing hardcoded paths
SUBST_FILES.hpath=	unix/vncserver/vncserver.in
SUBST_FILES.hpath+=	vncserver.pl
SUBST_SED.hpath+=	-e 's|/usr/local/vnc/classes|${PREFIX}/share/vnc/classes|g'
SUBST_VARS.hpath+=	PREFIX X11BASE

REPLACE_PERL+=	unix/vncserver
REPLACE_PERL+=	vncserver.pl

post-extract:
	cd ${WRKDIR} && ${EXTRACTOR} ${_DISTDIR}/${XORG_SERVER_FILE}.tar.xz
	cp -r ${WRKDIR}/${XORG_SERVER_FILE}/* ${WRKSRC}/unix/xserver
	cp ${FILESDIR}/vncserver.pl ${WRKSRC}

post-patch:
	cd ${WRKSRC}/unix/xserver && ${PATCH} --batch -p1 <../xserver120.patch

# suggested by BUILDING.txt:
#./configure --with-pic --without-dtrace --disable-static --disable-dri \
#      --disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
#      --disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
#      --disable-config-dbus --disable-config-hal --disable-config-udev \
#      --disable-dri2 --enable-install-libxf86config --enable-glx \
#      --with-default-font-path="catalogue:/etc/X11/fontpath.d,built-ins" \
#      --with-fontdir=/usr/share/X11/fonts \
#      --with-xkb-path=/usr/share/X11/xkb \
#      --with-xkb-output=/var/lib/xkb \
#      --with-xkb-bin-directory=/usr/bin \
#      --with-serverconfig-path=/usr/lib[64]/xorg \
#      --with-dri-driver-path=/usr/lib[64]/dri \
#      {additional configure options}

XORG_CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}
XORG_CONFIGURE_ARGS+=	--disable-xwayland --disable-kdrive --disable-xephyr
XORG_CONFIGURE_ARGS+=	--disable-static --disable-xinerama --without-dtrace
XORG_CONFIGURE_ARGS+=	--disable-xorg --disable-xnest --disable-xvfb --disable-dmx
XORG_CONFIGURE_ARGS+=	--disable-config-hal --disable-config-udev --with-pic
XORG_CONFIGURE_ARGS+=	--disable-unit-tests --disable-devel-docs --disable-selective-werror
XORG_CONFIGURE_ARGS+=	--disable-dri --enable-dri2 --disable-dri3 --enable-glx --enable-glx-tls

EGDIR=			share/examples/tigervnc
INSTALLATION_DIRS+=	${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/pam.d
MAKE_DIRS+=		${PKG_SYSCONFDIR}/tigervnc
CONF_FILES+=		${EGDIR}/tigervnc ${PKG_SYSCONFDIR}/pam.d/tigervnc
CONF_FILES+=		${EGDIR}/vncserver-config-defaults ${PKG_SYSCONFDIR}/tigervnc/vncserver-config-defaults
CONF_FILES+=		${EGDIR}/vncserver-config-mandatory ${PKG_SYSCONFDIR}/tigervnc/vncserver-config-mandatory
CONF_FILES+=		${EGDIR}/vncserver.users ${PKG_SYSCONFDIR}/tigervnc/vncserver.users

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vncserver.pl ${DESTDIR}${PREFIX}/bin/vncserver
	${MV} ${DESTDIR}${PREFIX}/etc/pam.d/tigervnc ${DESTDIR}${PREFIX}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/tigervnc/vncserver-config-defaults ${DESTDIR}${PREFIX}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/tigervnc/vncserver-config-mandatory ${DESTDIR}${PREFIX}/${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/tigervnc/vncserver.users ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} != "modular"
# when using native X, tigervnc server can't find xkb rules or xkbcomp without the following:
XORG_CONFIGURE_ARGS+=	--with-xkb-path=${X11BASE}/lib/X11/xkb
XORG_CONFIGURE_ARGS+=	--with-xkb-bin-directory=${X11BASE}/bin
.else
DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp
.endif

pre-configure:
	cd ${WRKSRC}/unix/xserver && \
	${PKGSRC_SETENV} ACLOCAL_PATH=${X11BASE}/share/aclocal \
		autoreconf -fvi &&	\
	${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV} CONFIG_SHELL=${BASH}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}	\
			./configure ${XORG_CONFIGURE_ARGS}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
BUILDLINK_API_DEPENDS.fltk+=	fltk>=1.3.3
.include "../../x11/fltk13/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
