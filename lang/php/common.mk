# $NetBSD: common.mk,v 1.11 2023/12/17 16:18:36 zafer Exp $
# used by lang/php56/Makefile.common
# used by lang/php74/Makefile.common
# used by lang/php80/Makefile.common
# used by lang/php81/Makefile.common
# used by lang/php82/Makefile.common
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
