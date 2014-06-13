# $NetBSD: common.mk,v 1.2 2014/06/13 02:58:19 obache Exp $
# used by lang/php53/Makefile.common
# used by lang/php54/Makefile.common
# used by lang/php55/Makefile.common
# 
.if !defined(PHPCOMMON_MK)
PHPCOMMON_MK=	defined

DISTNAME?=		php-${PHP_BASE_VERS}

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
