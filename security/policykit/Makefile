# $NetBSD: Makefile,v 1.23 2012/09/15 10:06:17 obache Exp $
#

POLICYKIT_VER=		0.9
DISTNAME=		PolicyKit-${POLICYKIT_VER}
PKGNAME=		policykit-${POLICYKIT_VER}
PKGREVISION=		12
CATEGORIES=		security
MASTER_SITES=		http://hal.freedesktop.org/releases/

MAINTAINER=		netbsd-desktop@NetBSD.org
HOMEPAGE=		http://hal.freedesktop.org/
COMMENT=		Framework for managing admin policies and privileges
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir
BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

PKG_SYSCONFSUBDIR=	PolicyKit

EGDIR=		${PREFIX}/share/examples/policykit
CONF_FILES+=	${EGDIR}/PolicyKit.conf ${PKG_SYSCONFDIR}/PolicyKit.conf
CONF_FILES+=	${EGDIR}/org.freedesktop.PolicyKit.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.PolicyKit.conf
#CONF_FILES+=	${EGDIR}/polkit ${PKG_SYSCONFBASE}/pam.d/polkit
#CONF_FILES+=	${EGDIR}/polkit-bash-completion.sh ${PKG_SYSCONFDIR}/profile.d/polkit-bash-completion.sh

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config autoconf
USE_LIBTOOL=		YES

USE_LANGUAGES=		c99

AUTOCONF_REQD=		2.59

POLICYKIT_USER?=	polkit
POLICYKIT_GROUP?=	polkit
PKG_GROUPS=		${POLICYKIT_GROUP}
PKG_USERS=		${POLICYKIT_USER}:${POLICYKIT_GROUP}
PKG_GROUPS_VARS+=	POLICYKIT_GROUP
PKG_USERS_VARS+=	POLICYKIT_USER

PKGCONFIG_OVERRIDE+=	data/polkit-dbus.pc.in
PKGCONFIG_OVERRIDE+=	data/polkit-grant.pc.in
PKGCONFIG_OVERRIDE+=	data/polkit.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-polkit-user=${POLICYKIT_USER}
CONFIGURE_ARGS+=	--with-polkit-group=${POLICYKIT_GROUP}
CONFIGURE_ARGS+=	--disable-selinux

OWN_DIRS_PERMS+=	${VARBASE}/lib/PolicyKit \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/lib/PolicyKit-public \
				${POLICYKIT_USER} ${REAL_ROOT_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/lib/misc ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
CONF_FILES_PERMS+=	/dev/null ${VARBASE}/lib/misc/PolicyKit.reload \
				${POLICYKIT_USER} ${POLICYKIT_GROUP} 0664

SPECIAL_PERMS+=		${PREFIX}/libexec/polkit-explicit-grant-helper \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 2555
SPECIAL_PERMS+=		${PREFIX}/libexec/polkit-grant-helper \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 2555
SPECIAL_PERMS+=		${PREFIX}/libexec/polkit-read-auth-helper \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 2555
SPECIAL_PERMS+=		${PREFIX}/libexec/polkit-read-grant-helper \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 2555
SPECIAL_PERMS+=		${PREFIX}/libexec/polkit-revoke-helper \
				${REAL_ROOT_USER} ${POLICYKIT_GROUP} 2555

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly"
post-install:
	${INSTALL_DATA} ${FILESDIR}/PolicyKit.conf.NetBSD ${DESTDIR}${EGDIR}/PolicyKit.conf
.endif

BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
