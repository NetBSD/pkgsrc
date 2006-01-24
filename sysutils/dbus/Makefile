# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:33 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=	1

PKG_USERS=	messagebus:messagebus::System\ message\ bus:${VARBASE}/run/dbus:${NOLOGIN}
PKG_GROUPS=	messagebus

MAKE_DIRS=	${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/system.d

RCD_SCRIPTS=	dbus

EGDIR=		${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

.include "../../mk/bsd.pkg.mk"
