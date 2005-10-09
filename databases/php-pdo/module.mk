# $NetBSD: module.mk,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

# Items common for all PDO drivers

MODNAME=		PDO_${PDO_DRIVER:tu}
PKGMODNAME=		pdo_${PDO_DRIVER}
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}
PKGREVISION=		# empty
PDO_VERSION?=		1.0RC1
PECL_VERSION?=		${PDO_VERSION}
CATEGORIES+=		databases
MAINTAINER=		jdolecek@NetBSD.org
COMMENT=		PHP PDO extension for ${PDO_COMMENT} databases

.include "../../databases/php-pdo/buildlink3.mk"
