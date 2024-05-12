# $NetBSD: common.mk,v 1.12 2024/05/12 14:42:22 taca Exp $
# used by lang/php56/Makefile.common
# used by lang/php74/Makefile.common
# used by lang/php81/Makefile.common
# used by lang/php82/Makefile.common
# used by lang/php83/Makefile.common
# 
.if !defined(PHPCOMMON_MK)
PHPCOMMON_MK=	defined

DISTNAME?=		php-${PHP_VERSION}

.if !defined(PECL_VERSION)
MASTER_SITES?=		https://www.php.net/distributions/
EXTRACT_SUFX?=		.tar.xz
.endif

HOMEPAGE?=		https://www.php.net/

PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PKG_SYSCONFVAR?=	php

.include "../../lang/php/phpversion.mk"
.endif	# PHPCOMMON_MK
