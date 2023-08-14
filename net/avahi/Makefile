# $NetBSD: Makefile,v 1.102 2023/08/14 05:24:57 wiz Exp $

.include "Makefile.common"

PKGREVISION=		6

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Facilitate service discovery on a local network

CONFIGURE_ARGS+=	--disable-gtk3

PKG_USERS=		${AVAHI_USER}:${AVAHI_GROUP}
PKG_GROUPS=		${AVAHI_GROUP}
PKG_GECOS.${AVAHI_USER}=	Avahi user

RCD_SCRIPTS=		avahidaemon

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

INSTALLATION_DIRS+=	share/doc/avahi

MAKE_DIRS+=	${PKG_SYSCONFDIR}/services

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/HACKING ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/INSTALL ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/README ${DESTDIR}${PREFIX}/share/doc/avahi
	${INSTALL_DATA} ${WRKSRC}/docs/TODO ${DESTDIR}${PREFIX}/share/doc/avahi

.include "../../mk/bsd.pkg.mk"
