# $NetBSD: options.mk,v 1.8 2014/05/09 07:36:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gps
PKG_SUPPORTED_OPTIONS=	syslog sqlite readline python pgsql
PKG_SUGGESTED_OPTIONS=	syslog sqlite readline python

.include "../../mk/bsd.options.mk"


################
##  READLINE  ##
################

.if !empty(PKG_OPTIONS:Mreadline)
CONFIGURE_ARGS+= --enable-gpl
.include "../../mk/readline.buildlink3.mk"
.else
CONFIGURE_ARGS+= --disable-readline
.endif


######################
##  SYSLOG SUPPORT  ##
######################

.if empty(PKG_OPTIONS:Msyslog)
CONFIGURE_ARGS+= --disable-syslog
.endif


######################
##  SQLITE SUPPORT  ##
######################

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+= --with-sqlite=embedded
.else
CONFIGURE_ARGS+= --without-sqlite
.endif


##########################
##  POSTGRESQL SUPPORT  ##
##########################

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+= --with-postgresql=${PREFIX}
.include "../../mk/pgsql.buildlink3.mk"
.endif


##############################
##  PYTHON / PYGTK SUPPORT  ##
##############################

# It appears that GPS can no longer be built without python
# Leave it as a (default) option until confirmed
.if empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+= --without-python --disable-pygtk --disable-pygobject
.else
MY_CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+=	--with-python=${PREFIX}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2
.include "../../lang/python/pyversion.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.endif
