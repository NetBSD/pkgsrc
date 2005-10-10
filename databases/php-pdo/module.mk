# $NetBSD: module.mk,v 1.3 2005/10/10 14:12:05 tv Exp $

# Items common for all PDO drivers

PDO_DRIVER_TR=		echo ${PDO_DRIVER:Q} | tr a-z A-Z
MODNAME=		PDO_${PDO_DRIVER_TR:sh}
PKGMODNAME=		pdo_${PDO_DRIVER}
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PDO_VERSION?=		1.0RC1
PECL_VERSION?=		${PDO_VERSION}
CATEGORIES+=		databases
MAINTAINER=		jdolecek@NetBSD.org
COMMENT=		PHP PDO extension for ${PDO_COMMENT} databases

.include "../../databases/php-pdo/buildlink3.mk"
