# $NetBSD: Makefile,v 1.6 2005/08/23 11:48:51 rillig Exp $
#

.include "Makefile.common"

PKG_USERS=	messagebus:messagebus::System\ message\ bus:${VARBASE}/run/dbus:${NOLOGIN}
PKG_GROUPS=	messagebus

MAKE_DIRS=	${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/system.d

RCD_SCRIPTS=	dbus

EGDIR=		${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

.include "../../mk/bsd.pkg.mk"
