# $NetBSD: options.mk,v 1.1 2005/10/07 11:30:35 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bacula
PKG_SUPPORTED_OPTIONS=	catalog-sqlite catalog-pgsql
PKG_SUGGESTED_OPTIONS=	catalog-sqlite

.include "../../mk/bsd.options.mk"

# Too bad -1-6's make doesn't have :[#] modifier
.for _option_ in catalog
. if empty(PKG_OPTIONS:M${_option_}-*)
PKG_FAIL_REASON+=	"There must one and only one ${_option_} defined."
. endif
.endfor

# Other options

BACULA_GROUP?=		bacula
BACULA_DIR_USER?=	bacula-dir
BACULA_SD_USER?=	bacula-sd

BUILD_DEFS=	BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP
