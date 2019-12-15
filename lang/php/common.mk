# $NetBSD: common.mk,v 1.8 2019/12/15 18:15:48 taca Exp $
# used by lang/php56/Makefile.common
# used by lang/php71/Makefile.common
# used by lang/php72/Makefile.common
# used by lang/php73/Makefile.common
# used by lang/php74/Makefile.common
# 
.if !defined(PHPCOMMON_MK)
PHPCOMMON_MK=	defined

DISTNAME?=		php-${PHP_VERSION}

.if !defined(PECL_VERSION)
MASTER_SITES?=		https://www.php.net/distributions/ \
			https://uk.php.net/distributions/ \
			https://de.php.net/distributions/ \
			https://us.php.net/distributions/
EXTRACT_SUFX?=		.tar.xz
.endif

HOMEPAGE?=		https://www.php.net/

PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PKG_SYSCONFVAR?=	php

.include "../../lang/php/phpversion.mk"
.endif	# PHPCOMMON_MK
