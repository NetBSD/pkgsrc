# $NetBSD: Makefile,v 1.100 2020/06/02 08:22:34 adam Exp $

PKGREVISION= 5
.include "../../devel/GConf/Makefile.common"

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--disable-defaults-service
CONFIGURE_ARGS+=	--with-openldap=no

OWN_DIRS=	${PKG_SYSCONFDIR}/2
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.defaults
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.mandatory
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.system

EGDIR=		${PREFIX}/share/examples/GConf
CONF_FILES=	${EGDIR}/path ${PKG_SYSCONFDIR}/2/path

REPLACE_PYTHON=		gsettings/gsettings-schema-convert
INSTALLATION_DIRS=	share/gconf/schemas

BUILDLINK_ABI_DEPENDS.dbus-glib+=	dbus-glib>=0.74
.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../mk/bsd.pkg.mk"
