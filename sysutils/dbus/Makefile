# $NetBSD: Makefile,v 1.10 2006/03/31 16:40:41 joerg Exp $
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

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
