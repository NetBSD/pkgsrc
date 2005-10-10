# $NetBSD: options.mk,v 1.3 2005/10/10 15:27:45 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	catalog-sqlite catalog-pgsql catalog-mysql
PKG_SUGGESTED_OPTIONS=		catalog-sqlite

.include "../../mk/bsd.options.mk"

# Other options

BACULA_GROUP?=		bacula
BACULA_DIR_USER?=	bacula-dir
BACULA_SD_USER?=	bacula-sd

BUILD_DEFS=	BACULA_DIR_USER BACULA_SD_USER BACULA_GROUP
