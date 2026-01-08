# $NetBSD: common.mk,v 1.16 2026/01/08 14:34:35 taca Exp $
# used by lang/pear/Makefile
# used by lang/php56/Makefile.common
# used by lang/php74/Makefile.common
# used by lang/php82/Makefile.common
# used by lang/php83/Makefile.common
# used by lang/php84/Makefile.common
# used by lang/php85/Makefile.common
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
