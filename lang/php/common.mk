# $NetBSD: common.mk,v 1.5 2016/09/11 17:14:46 taca Exp $
# used by lang/php56/Makefile.common
# used by lang/php70/Makefile.common
# used by lang/php71/Makefile.common
# 
.if !defined(PHPCOMMON_MK)
PHPCOMMON_MK=	defined

DISTNAME?=		php-${PHP_VERSION}

.if !defined(PECL_VERSION)
MASTER_SITES?=		http://www.php.net/distributions/ \
			http://uk.php.net/distributions/ \
			http://de.php.net/distributions/ \
			http://us.php.net/distributions/
EXTRACT_SUFX?=		.tar.bz2
.endif

HOMEPAGE?=		http://www.php.net/

PLIST_SUBST+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PKG_SYSCONFVAR?=	php

.include "../../lang/php/phpversion.mk"
.endif	# PHPCOMMON_MK
