# $NetBSD: module.mk,v 1.7 2006/06/02 18:27:55 joerg Exp $

# Items common for all PDO drivers

.if !empty(PDO_DRIVER)
_PDO_SEP=		_
.else
_PDO_SEP=		# empty
.endif

PDO_DRIVER_TR=		${ECHO} ${PDO_DRIVER:Q} | ${TR} a-z A-Z
MODNAME=		PDO${_PDO_SEP}${PDO_DRIVER_TR:sh}
PKGMODNAME=		pdo${_PDO_SEP}${PDO_DRIVER}
PECL_VERSION?=		${PDO_VERSION}
PKGNAME=		${PHP_PKG_PREFIX}-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}

CONFLICTS=		php-pdo${_PDO_SEP}${PDO_DRIVER}-[0-9]*

CATEGORIES+=		databases
MAINTAINER=		jdolecek@NetBSD.org
COMMENT=		PHP PDO extension for ${PDO_COMMENT} databases

# needed due to (broken?) PDO_* configure checks
CONFIGURE_ENV+=		PHP_PDO_SHARED="1"

PHP_VERSIONS_ACCEPTED=	5

.include "../../lang/php/phpversion.mk"
