# $NetBSD: options.mk,v 1.1 2011/11/02 21:13:17 marino Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tbox-dfly
PKG_SUPPORTED_OPTIONS=	pgsql mysql webui anybody lsof emailer
PKG_SUGGESTED_OPTIONS=	pgsql webui
PLIST_VARS+=		WEBUI

.include "../../mk/bsd.options.mk"

########################################
#  WEB INTERFACE AND DATABASE OPTIONS  #
########################################

.if  empty(PKG_OPTIONS:Mpgsql) && empty(PKG_OPTIONS:Mmysql)
PKG_FAIL_REASON+=	"Tinderbox requires a database or confirmation you have already installed on."
PKG_FAIL_REASON+=	"Please select either pgsql or mysql"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwebui)
PLIST.WEBUI=	yes
.include "../../lang/php/phpversion.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=2.12:../../databases/p5-DBD-postgresql
.if !empty(PKG_OPTIONS:Mwebui)
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2_Driver_pgsql:../../databases/pear-MDB2_Driver_pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=5.1:../../databases/php-pgsql
.endif
.endif

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=4:../../databases/p5-DBD-mysql
.if !empty(PKG_OPTIONS:Mwebui)
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2_Driver_mysql>1.5:../../databases/pear-MDB2_Driver_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=5.1:../../databases/php-mysql
.endif
.endif

#####################
#  LIST OPEN FILES  #
#####################

.if !empty(PKG_OPTIONS:Mlsof)
DEPENDS+=		lsof>=4.83:../../sysutils/lsof
PKG_FAIL_REASON+=	"LSOF package is broken for DragonFly, remove the option for now."
.endif

#########################
#  EMAIL NOTIFICATIONS  #
#########################

.if !empty(PKG_OPTIONS:Memailer)
DEPENDS+=	p5-Net>=1.21:../../net/p5-Net
.endif
