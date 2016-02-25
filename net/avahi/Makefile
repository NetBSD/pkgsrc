# $NetBSD: Makefile,v 1.60 2016/02/25 16:20:50 jperkin Exp $

DISTNAME=		avahi-0.6.31
PKGREVISION=		24
CATEGORIES=		net
MASTER_SITES=		http://avahi.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://avahi.org/
COMMENT=		Facilitate service discovery on a local network
LICENSE=		gnu-lgpl-v2.1

EXTRACT_USING=		bsdtar

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext
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
PKGCONFIG_OVERRIDE+=	avahi-ui-gtk3.pc.in
PKGCONFIG_OVERRIDE+=	avahi-ui-sharp.pc.in
PKGCONFIG_OVERRIDE+=	avahi-ui.pc.in

AVAHI_USER=		avahi
AVAHI_GROUP=		avahi
RCD_SCRIPTS=		avahidaemon
BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE
PLIST_SRC=		${PKGDIR}/PLIST
PKG_SYSCONFSUBDIR=	avahi
USE_LANGUAGES=		c c++

PKG_USERS=		${AVAHI_USER}:${AVAHI_GROUP}
PKG_GROUPS=		${AVAHI_GROUP}
PKG_GECOS.${AVAHI_USER}=	Avahi user

.include "options.mk"

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
CPPFLAGS.SunOS+=	--std=c99 -D_XOPEN_SOURCE=600
# Not yet reported upstream.
CPPFLAGS.Darwin+=	-D__APPLE_USE_RFC_3542

PLIST_SRC+=		${PKGDIR}/PLIST.shared

CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-daemon.conf \
			${PKG_SYSCONFDIR}/avahi-daemon.conf
CONF_FILES+=		${PREFIX}/share/examples/avahi/hosts \
			${PKG_SYSCONFDIR}/hosts
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dnsconfd.action \
			${PKG_SYSCONFDIR}/avahi-dnsconfd.action
CONF_FILES+=		${PREFIX}/share/examples/avahi/services/sftp-ssh.service \
			${PKG_SYSCONFDIR}/services/sftp-ssh.service
CONF_FILES+=		${PREFIX}/share/examples/avahi/services/ssh.service \
			${PKG_SYSCONFDIR}/services/ssh.service
CONF_FILES+=		${PREFIX}/share/examples/avahi/avahi-dbus.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/avahi-dbus.conf

CONFIGURE_ARGS+=	--with-avahi-user=${AVAHI_USER}
CONFIGURE_ARGS+=	--with-avahi-group=${AVAHI_GROUP}
CONFIGURE_ARGS+=	--with-avahi_priv_access_group=${REAL_ROOT_GROUP}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-dbus-system-socket=${VARBASE}/run/dbus/system_bus_socket
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--disable-doxygen-doc
CONFIGURE_ARGS+=	--disable-doxygen-dot
CONFIGURE_ARGS+=	--disable-doxygen-html --disable-doxygen-xml
CONFIGURE_ARGS+=	--disable-xmltoman
CONFIGURE_ARGS+=	--disable-autoipd
CONFIGURE_ARGS+=	--with-distro=none

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples
INSTALL_MAKE_FLAGS+=	dbusservicedir=${PREFIX}/share/examples/avahi

INSTALLATION_DIRS+=	share/doc/avahi

MAKE_DIRS+=	${PKG_SYSCONFDIR}/services

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/HACKING ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${DESTDIR}${PREFIX}/share/doc/avahi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libdaemon+=	libdaemon>=0.14
.include "../../devel/libdaemon/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
