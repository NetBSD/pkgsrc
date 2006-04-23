# $NetBSD: Makefile,v 1.12 2006/04/23 00:12:42 jlam Exp $
#

.include "Makefile.common"

PKGREVISION=	1

PKG_GROUPS=	messagebus
PKG_USERS=	messagebus:messagebus

PKG_GECOS.messagebus=	System message bus
PKG_HOME.messagebus=	${VARBASE}/run/dbus

MAKE_DIRS=	${PKG_SYSCONFDIR}/event.d
MAKE_DIRS+=	${PKG_SYSCONFDIR}/system.d

RCD_SCRIPTS=	dbus

EGDIR=		${PREFIX}/share/examples/dbus
CONF_FILES=	${EGDIR}/session.conf ${PKG_SYSCONFDIR}/session.conf
CONF_FILES+=	${EGDIR}/system.conf ${PKG_SYSCONFDIR}/system.conf

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
