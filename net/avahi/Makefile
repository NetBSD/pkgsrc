# $NetBSD: Makefile,v 1.12 2009/06/09 13:07:13 wiz Exp $

DISTNAME=		avahi-0.6.25
CATEGORIES=		net
MASTER_SITES=		http://avahi.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://avahi.org/
COMMENT=		Facilitate service discovery on a local network
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config gmake intltool msgfmt
MAKE_JOBS_SAFE=		no

PKGCONFIG_OVERRIDE+=	avahi-client.pc.in
PKGCONFIG_OVERRIDE+=	avahi-compat-howl.pc.in
PKGCONFIG_OVERRIDE+=	avahi-compat-libdns_sd.pc.in
PKGCONFIG_OVERRIDE+=	avahi-core.pc.in
PKGCONFIG_OVERRIDE+=	avahi-glib.pc.in
PKGCONFIG_OVERRIDE+=	avahi-gobject.pc.in
PKGCONFIG_OVERRIDE+=	avahi-qt3.pc.in
PKGCONFIG_OVERRIDE+=	avahi-qt4.pc.in
PKGCONFIG_OVERRIDE+=	avahi-sharp.pc.in
PKGCONFIG_OVERRIDE+=	avahi-ui-sharp.pc.in
PKGCONFIG_OVERRIDE+=	avahi-ui.pc.in

AVAHI_USER=		avahi
AVAHI_GROUP=		avahi
RCD_SCRIPTS=		avahidaemon
BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE
PLIST_SRC=		${PKGDIR}/PLIST
PKG_SYSCONFSUBDIR=	avahi
USE_LANGUAGES=		c c++
MAKE_DIRS=		${PKG_SYSCONFDIR}/services

PKG_USERS=		${AVAHI_USER}:${AVAHI_GROUP}
PKG_GROUPS=		${AVAHI_GROUP}
PKG_GECOS.${AVAHI_USER}=	Avahi user

.include "options.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-D_NETBSD_SOURCE
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.shared

CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-daemon.conf \
			${PKG_SYSCONFDIR}/avahi-daemon.conf
CONF_FILES+=		${PREFIX}/share/examples/avahi/hosts \
			${PKG_SYSCONFDIR}/hosts
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dnsconfd.action \
			${PKG_SYSCONFDIR}/avahi-dnsconfd.action
CONF_FILES+=		${PREFIX}/share/examples/avahi/ssh.service \
			${PKG_SYSCONFDIR}/services/ssh.service
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dbus.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/avahi-dbus.conf

CONFIGURE_ARGS+=	--with-avahi-user=${AVAHI_USER}
CONFIGURE_ARGS+=	--with-avahi-group=${AVAHI_GROUP}
CONFIGURE_ARGS+=	--with-avahi_priv_access_group=${REAL_ROOT_GROUP}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--disable-qt3
CONFIGURE_ARGS+=	--disable-qt4
CONFIGURE_ARGS+=	--disable-mono
CONFIGURE_ARGS+=	--disable-monodoc
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--disable-doxygen-dot
CONFIGURE_ARGS+=	--disable-doxygen-html
CONFIGURE_ARGS+=	--disable-xmltoman
CONFIGURE_ARGS+=	--disable-autoipd

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-distro=none
.endif

INSTALLATION_DIRS+=	share/examples/avahi
INSTALLATION_DIRS+=	share/doc/avahi

MAKE_DIRS+=	${PKG_SYSCONFDIR}/services

post-install:
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/avahi-daemon.conf \
		${DESTDIR}${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/hosts \
		${DESTDIR}${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-dnsconfd/avahi-dnsconfd.action \
		${DESTDIR}${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/ssh.service \
		${DESTDIR}${PREFIX}/share/examples/avahi
	${INSTALL_DATA} ${WRKSRC}/avahi-daemon/avahi-dbus.conf \
		${DESTDIR}${PREFIX}/share/examples/avahi/avahi-dbus.conf
	${INSTALL_DATA} ${WRKSRC}/docs/HACKING ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${DESTDIR}${PREFIX}/share/doc/avahi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libdaemon/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
