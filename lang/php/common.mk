# $NetBSD: common.mk,v 1.14.2.1 2025/04/08 18:27:50 bsiegert Exp $
# used by lang/pear/Makefile
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

.include "../../lang/php/phpversion.mk"

PKG_SYSCONFSUBDIR?=	php/${PHP_API_VERS}

.endif	# PHPCOMMON_MK
