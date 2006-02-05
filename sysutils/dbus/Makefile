# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:49 joerg Exp $
#

.include "Makefile.common"
PKGREVISION=	2

PKG_USERS=	messagebus:messagebus::System\ message\ bus:${VARBASE}/run/dbus:${NOLOGIN}
PKG_GROUPS=	messagebus

MAKE_DIRS=	${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/system.d

RCD_SCRIPTS=	dbus

EGDIR=		${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

.include "../../mk/bsd.pkg.mk"
