# $NetBSD: Makefile,v 1.2 2010/03/21 17:07:52 jdolecek Exp $

DISTNAME=	php-extensions-${PHP_BASE_VERS}
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP 5.2 HTML-embedded scripting language

# base PHP 5.3.x package
DEPENDS+=	php>=${PHP_BASE_VERS}<6:../../lang/php53
DEPENDS+=	${APACHE_PKG_PREFIX}-php53>=${PHP_BASE_VERS}<6:../../www/ap-php

# extensions buildable with both PHP 5.2.x and PHP 5.3.x
DEPENDS+=	php53-apc>=${PHP_BASE_VERS}<6:../../www/php-apc
DEPENDS+=	php53-bcmath>=${PHP_BASE_VERS}<6:../../math/php-bcmath
DEPENDS+=	php53-bz2>=${PHP_BASE_VERS}<6:../../archivers/php-bz2
DEPENDS+=	php53-calendar>=${PHP_BASE_VERS}<6:../../time/php-calendar
DEPENDS+=	php53-curl>=${PHP_BASE_VERS}<6:../../www/php-curl
DEPENDS+=	php53-dba>=${PHP_BASE_VERS}<6:../../databases/php-dba
DEPENDS+=	php53-dom>=${PHP_BASE_VERS}<6:../../textproc/php-dom
DEPENDS+=	php53-eaccelerator>=${PHP_BASE_VERS}<6:../../www/php-eaccelerator
DEPENDS+=	php53-enchant>=${PHP_BASE_VERS}<6:../../textproc/php-enchant
DEPENDS+=	php53-exif>=${PHP_BASE_VERS}<6:../../graphics/php-exif
DEPENDS+=	php53-ftp>=${PHP_BASE_VERS}<6:../../net/php-ftp
DEPENDS+=	php53-gd>=${PHP_BASE_VERS}<6:../../graphics/php-gd
DEPENDS+=	php53-gettext>=${PHP_BASE_VERS}<6:../../devel/php-gettext
DEPENDS+=	php53-gmp>=${PHP_BASE_VERS}<6:../../devel/php-gmp
DEPENDS+=	php53-iconv>=${PHP_BASE_VERS}<6:../../converters/php-iconv
DEPENDS+=	php53-imap>=${PHP_BASE_VERS}<6:../../mail/php-imap
DEPENDS+=	php53-intl>=${PHP_BASE_VERS}<6:../../textproc/php-intl
DEPENDS+=	php53-json>=${PHP_BASE_VERS}<6:../../textproc/php-json
DEPENDS+=	php53-ldap>=${PHP_BASE_VERS}<6:../../databases/php-ldap
DEPENDS+=	php53-mbstring>=${PHP_BASE_VERS}<6:../../converters/php-mbstring
DEPENDS+=	php53-mcrypt>=${PHP_BASE_VERS}<6:../../security/php-mcrypt
DEPENDS+=	php53-mssql>=${PHP_BASE_VERS}<6:../../databases/php-mssql
DEPENDS+=	php53-mysql>=${PHP_BASE_VERS}<6:../../databases/php-mysql
DEPENDS+=	php53-mysqli>=${PHP_BASE_VERS}<6:../../databases/php-mysqli
# broken
# DEPENDS+=	php53-odbc>=${PHP_BASE_VERS}<6:../../databases/php-odbc
DEPENDS+=	php53-pcntl>=${PHP_BASE_VERS}<6:../../devel/php-pcntl
DEPENDS+=	php53-pdflib>=${PHP_BASE_VERS}<6:../../print/php-pdflib
DEPENDS+=	php53-pdo>=${PHP_BASE_VERS}<6:../../databases/php-pdo
DEPENDS+=	php53-pdo_dblib>=${PHP_BASE_VERS}<6:../../databases/php-pdo_dblib
DEPENDS+=	php53-pdo_mysql>=${PHP_BASE_VERS}<6:../../databases/php-pdo_mysql
DEPENDS+=	php53-pdo_pgsql>=${PHP_BASE_VERS}<6:../../databases/php-pdo_pgsql
DEPENDS+=	php53-pdo_sqlite>=${PHP_BASE_VERS}<6:../../databases/php-pdo_sqlite
DEPENDS+=	php53-pgsql>=${PHP_BASE_VERS}<6:../../databases/php-pgsql
DEPENDS+=	php53-posix>=${PHP_BASE_VERS}<6:../../devel/php-posix
DEPENDS+=	php53-shmop>=${PHP_BASE_VERS}<6:../../devel/php-shmop
DEPENDS+=	php53-snmp>=${PHP_BASE_VERS}<6:../../net/php-snmp
DEPENDS+=	php53-soap>=${PHP_BASE_VERS}<6:../../net/php-soap
DEPENDS+=	php53-sockets>=${PHP_BASE_VERS}<6:../../net/php-sockets
DEPENDS+=	php53-sqlite>=${PHP_BASE_VERS}<6:../../databases/php-sqlite
DEPENDS+=	php53-sysvmsg>=${PHP_BASE_VERS}<6:../../devel/php-sysvmsg
DEPENDS+=	php53-sysvsem>=${PHP_BASE_VERS}<6:../../devel/php-sysvsem
DEPENDS+=	php53-sysvshm>=${PHP_BASE_VERS}<6:../../devel/php-sysvshm
DEPENDS+=	php53-wddx>=${PHP_BASE_VERS}<6:../../textproc/php-wddx
DEPENDS+=	php53-xsl>=${PHP_BASE_VERS}<6:../../textproc/php-xsl
DEPENDS+=	php53-xmlrpc>=${PHP_BASE_VERS}<6:../../net/php-xmlrpc
DEPENDS+=	php53-zip>=${PHP_BASE_VERS}<6:../../archivers/php-zip
DEPENDS+=	php53-zlib>=${PHP_BASE_VERS}<6:../../archivers/php-zlib

# PHP 5.3.x only extensions
# not yet
#DEPENDS+=	php53-mysqlnd>=${PHP_BASE_VERS}<6:../../databases/php-mysqlnd

META_PACKAGE=	yes

.include "../../lang/php53/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
