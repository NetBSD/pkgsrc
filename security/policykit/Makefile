# $NetBSD: Makefile,v 1.1.1.1 2008/11/22 03:33:38 jmcneill Exp $
#

POLICYKIT_VER=		0.9
DISTNAME=		PolicyKit-${POLICYKIT_VER}
PKGNAME=		policykit-${POLICYKIT_VER}
CATEGORIES=		security
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		Framework for managing admin policies and privileges

PKG_SYSCONFSUBDIR=	PolicyKit

EGDIR=		${PREFIX}/share/examples/policykit
CONF_FILES+=	${EGDIR}/PolicyKit.conf ${PKG_SYSCONFDIR}/PolicyKit.conf
CONF_FILES+=	${EGDIR}/org.freedesktop.PolicyKit.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.PolicyKit.conf
#CONF_FILES+=	${EGDIR}/polkit ${PKG_SYSCONFBASE}/pam.d/polkit
#CONF_FILES+=	${EGDIR}/polkit-bash-completion.sh ${PKG_SYSCONFDIR}/profile.d/polkit-bash-completion.sh

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.4
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

POLICYKIT_USER?=	polkit
POLICYKIT_GROUP?=	polkit
PKG_GROUPS=		${POLICYKIT_GROUP}
PKG_USERS=		${POLICYKIT_USER}:${POLICYKIT_GROUP}
PKG_GROUPS_VARS+=	POLICYKIT_GROUP
PKG_USERS_VARS+=	POLICYKIT_USER

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-polkit-user=${POLICYKIT_USER}
CONFIGURE_ARGS+=	--with-polkit-group=${POLICYKIT_GROUP}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
