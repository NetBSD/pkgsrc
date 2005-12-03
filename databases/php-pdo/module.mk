# $NetBSD: module.mk,v 1.5 2005/12/03 17:24:28 jdolecek Exp $

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
PKGNAME=		php-${PKGMODNAME}-${PHP_BASE_VERS}.${PECL_VERSION}

CATEGORIES+=		databases
MAINTAINER=		jdolecek@NetBSD.org
COMMENT=		PHP PDO extension for ${PDO_COMMENT} databases
