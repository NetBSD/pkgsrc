# $NetBSD: Makefile,v 1.2 2024/02/27 10:35:45 wiz Exp $

DISTNAME=	bulk-test-php-20240227
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

# Feel free to add packages without asking.
MAINTAINER=	jym@NetBSD.org
COMMENT=	Meta-package for testing PHP

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# Large programs and applications
DEPENDS+=	${PHP_PKG_PREFIX}-dotclear-[0-9]*:../../www/php-dotclear
DEPENDS+=	wordpress-[0-9]*:../../www/wordpress
DEPENDS+=	${PHP_PKG_PREFIX}-nextcloud-[0-9]*:../../www/php-nextcloud
DEPENDS+=	${PHP_PKG_PREFIX}-owncloud-[0-9]*:../../www/php-owncloud
DEPENDS+=	${PHP_PKG_PREFIX}-davical-[0-9]*:../../www/davical
# does not support the current 8.2 default of php
#DEPENDS+=	moodle-[0-9]*:../../www/moodle
DEPENDS+=	${PHP_PKG_PREFIX}-fpm-[0-9]*:../../www/php-fpm
DEPENDS+=	${PHP_PKG_PREFIX}-roundcube-[0-9]*:../../mail/roundcube

# libraries often used with PHP
DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring-[0-9]*:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-ldap-[0-9]*:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-pdo-[0-9]*:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql-[0-9]*:../../databases/php-pdo_pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-composer-[0-9]*:../../devel/php-composer
DEPENDS+=	${PHP_PKG_PREFIX}-ffi-[0-9]*:../../devel/php-ffi
DEPENDS+=	${PHP_PKG_PREFIX}-posix-[0-9]*:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-imagick-[0-9]*:../../graphics/php-imagick
DEPENDS+=	${PHP_PKG_PREFIX}-soap-[0-9]*:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
