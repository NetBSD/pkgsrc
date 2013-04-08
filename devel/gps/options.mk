# $NetBSD: options.mk,v 1.4 2013/04/08 11:17:11 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gps
PKG_SUPPORTED_OPTIONS=	syslog python sqlite
PKG_SUGGESTED_OPTIONS=	syslog sqlite

PLIST_VARS+=	pysupport

.include "../../mk/bsd.options.mk"


######################
##  SYSLOG SUPPORT  ##
######################

.if !empty(PKG_OPTIONS:Msyslog)
CONFIGURE_ARGS+= --enable-syslog=yes
.else
CONFIGURE_ARGS+= --enable-syslog=no
.endif


######################
##  SQLITE SUPPORT  ##
######################

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+= --with-sqlite=${PREFIX}
.include "../../databases/sqlite3/buildlink3.mk"
.endif


##########################
##  POSTGRESQL SUPPORT  ##
##########################

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+= --with-postgresql=${PREFIX}
.include "../../databases/postgresql90-client/buildlink3.mk"
.endif


##############################
##  PYTHON / PYGTK SUPPORT  ##
##############################

#
# Something is wrong with the pkgsrc versions of Python.  Both
# versions 2.6 and 2.7 will cause a core dump of gps because they
# contain undefined symbols in their dynamically loaded libraries.
# Since no version of Python < 3 can work with GPS, this option
# has been removed from the list.
#

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+= --with-python=${PREFIX}
CONFIGURE_ARGS+= --enable-shared-python=no
CONFIGURE_ARGS+= --enable-pygtk
PLIST.pysupport= yes
.include "../../lang/python/pyversion.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+= --without-python
CONFIGURE_ARGS+= --disable-pygtk
.endif
