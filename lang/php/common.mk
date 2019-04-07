# $NetBSD: common.mk,v 1.6 2019/04/07 05:03:41 taca Exp $
# used by lang/php56/Makefile.common
# used by lang/php70/Makefile.common
# used by lang/php71/Makefile.common
# 
.if !defined(PHPCOMMON_MK)
PHPCOMMON_MK=	defined

DISTNAME?=		php-${PHP_VERSION}

.if !defined(PECL_VERSION)
MASTER_SITES?=		https://www.php.net/distributions/ \
			https://uk.php.net/distributions/ \
			https://de.php.net/distributions/ \
			https://us.php.net/distributions/
EXTRACT_SUFX?=		.tar.bz2
.endif

HOMEPAGE?=		https://www.php.net/

PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PKG_SYSCONFVAR?=	php

.include "../../lang/php/phpversion.mk"
.endif	# PHPCOMMON_MK
