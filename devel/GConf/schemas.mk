# $NetBSD: schemas.mk,v 1.2 2009/06/14 22:57:59 joerg Exp $
#
# This Makefile fragment is intended to be included by packages that install
# GConf schema files.  It takes care of registering them in the GConf
# global configuration database.
#
# The following variables are automatically defined for free use in packages:
#    GCONFTOOL2           - The gconftool-2 binary program.
#    GCONF_CONFIG_SOURCE - URI of the global configuration database.
#    GCONF_SCHEMAS_DIR   - Directory where .schemas files are installed.
#
# The following variables can be defined by a package to register .entries
# and .schemas files:
#    GCONF_ENTRIES - A list of .entries files to register.  When using this
#                     variable, packages need to be fixed to not register
#                     them and to install those files to GCONF_SCHEMAS_DIR.
#    GCONF_SCHEMAS - A list of .schemas files to register.  When using this
#                     variable, packages need to be fixed to not register
#                     them and to install those files to GCONF_SCHEMAS_DIR.
#

.if !defined(GCONF_SCHEMAS_MK)
GCONF_SCHEMAS_MK=	# defined

# The gconftool-2 binary program.
GCONFTOOL2=		${BUILDLINK_PREFIX.GConf}/bin/gconftool-2

# Default configuration source (database).
.if defined(PKG_SYSCONFDIR.GConf)
GCONF_CONFIG_SOURCE=	xml::${PKG_SYSCONFDIR.GConf}/gconf/gconf.xml.defaults
.else
GCONF_CONFIG_SOURCE=	xml::${PKG_SYSCONFBASE}/gconf/gconf.xml.defaults
.endif

# Where .schemas files go.
GCONF_SCHEMAS_DIR=	${BUILDLINK_PREFIX.GConf}/share/gconf/schemas

.if defined(GNU_CONFIGURE) && !empty(GNU_CONFIGURE:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--disable-schemas-install
CONFIGURE_ARGS+=	--with-gconf-schema-file-dir=${GCONF_SCHEMAS_DIR:Q}
.endif

.if (defined(GCONF_SCHEMAS) && !empty(GCONF_SCHEMAS)) || \
    (defined(GCONF_ENTRIES) && !empty(GCONF_ENTRIES))
FILES_SUBST+=		GCONFTOOL2=${GCONFTOOL2:Q}
FILES_SUBST+=		GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE:Q}
FILES_SUBST+=		GCONF_ENTRIES=${GCONF_ENTRIES:Q}
FILES_SUBST+=		GCONF_SCHEMAS=${GCONF_SCHEMAS:Q}
FILES_SUBST+=		GCONF_SCHEMAS_DIR=${GCONF_SCHEMAS_DIR:Q}
INSTALL_TEMPLATES+=	${.CURDIR}/../../devel/GConf/files/install.tmpl
DEINSTALL_TEMPLATES+=	${.CURDIR}/../../devel/GConf/files/deinstall.tmpl
.endif

.include "../../mk/bsd.prefs.mk"
.include "../../devel/GConf/buildlink3.mk"

.endif	# GCONF_SCHEMAS_MK
