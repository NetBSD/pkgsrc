# $NetBSD: Makefile,v 1.81 2012/09/15 10:04:04 obache Exp $
#

.include "../../devel/GConf/Makefile.common"

PKGREVISION=		5

CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	ac_cv_header_ldap_h=no
CONFIGURE_ARGS+=	--disable-defaults-service

CONFLICTS+=	GConf2-[0-9]*

OWN_DIRS=	${PKG_SYSCONFDIR}/2
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.defaults
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.mandatory
OWN_DIRS+=	${PKG_SYSCONFDIR}/gconf.xml.system

EGDIR=		${PREFIX}/share/examples/GConf
CONF_FILES=	${EGDIR}/path ${PKG_SYSCONFDIR}/2/path

REPLACE_PYTHON=	gsettings/gsettings-schema-convert

# XXX: We need to use XML_CATALOGS here to register the installed DTD.
#      But we have to wait until a public identifier is choosen for it.

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gconf/schemas

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
