# $NetBSD: Makefile,v 1.22 2010/03/16 15:52:25 taca Exp $

DISTNAME=	php-extensions-${PHP_BASE_VERS}
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP 5.2 HTML-embedded scripting language

# base PHP 5.2.x package
DEPENDS+=	php>=${PHP_BASE_VERS}<5.3:../../lang/php5
DEPENDS+=	${APACHE_PKG_PREFIX}-php5>=${PHP_BASE_VERS}<5.3:../../www/ap-php

# extensions buildable with both PHP 5.2 and PHP 5.3
DEPENDS+=	php5-apc>=${PHP_BASE_VERS}<5.3:../../www/php-apc
DEPENDS+=	php5-bcmath>=${PHP_BASE_VERS}<5.3:../../math/php-bcmath
DEPENDS+=	php5-bz2>=${PHP_BASE_VERS}<5.3:../../archivers/php-bz2
DEPENDS+=	php5-calendar>=${PHP_BASE_VERS}<5.3:../../time/php-calendar
DEPENDS+=	php5-curl>=${PHP_BASE_VERS}<5.3:../../www/php-curl
DEPENDS+=	php5-dba>=${PHP_BASE_VERS}<5.3:../../databases/php-dba
DEPENDS+=	php5-dom>=${PHP_BASE_VERS}<5.3:../../textproc/php-dom
DEPENDS+=	php5-eaccelerator>=${PHP_BASE_VERS}<5.3:../../www/php-eaccelerator
DEPENDS+=	php5-exif>=${PHP_BASE_VERS}<5.3:../../graphics/php-exif
DEPENDS+=	php5-ftp>=${PHP_BASE_VERS}<5.3:../../net/php-ftp
DEPENDS+=	php5-gd>=${PHP_BASE_VERS}<5.3:../../graphics/php-gd
DEPENDS+=	php5-gettext>=${PHP_BASE_VERS}<5.3:../../devel/php-gettext
DEPENDS+=	php5-gmp>=${PHP_BASE_VERS}<5.3:../../devel/php-gmp
DEPENDS+=	php5-iconv>=${PHP_BASE_VERS}<5.3:../../converters/php-iconv
DEPENDS+=	php5-imap>=${PHP_BASE_VERS}<5.3:../../mail/php-imap
DEPENDS+=	php5-json>=${PHP_BASE_VERS}<5.3:../../textproc/php-json
DEPENDS+=	php5-ldap>=${PHP_BASE_VERS}<5.3:../../databases/php-ldap
DEPENDS+=	php5-mbstring>=${PHP_BASE_VERS}<5.3:../../converters/php-mbstring
DEPENDS+=	php5-mcrypt>=${PHP_BASE_VERS}<5.3:../../security/php-mcrypt
DEPENDS+=	php5-mssql>=${PHP_BASE_VERS}<5.3:../../databases/php-mssql
DEPENDS+=	php5-mysql>=${PHP_BASE_VERS}<5.3:../../databases/php-mysql
DEPENDS+=	php5-mysqli>=${PHP_BASE_VERS}<5.3:../../databases/php-mysqli
# broken
# DEPENDS+=	php5-odbc>=${PHP_BASE_VERS}<5.3:../../databases/php-odbc
DEPENDS+=	php5-pcntl>=${PHP_BASE_VERS}<5.3:../../devel/php-pcntl
DEPENDS+=	php5-pdflib>=${PHP_BASE_VERS}<5.3:../../print/php-pdflib
DEPENDS+=	php5-pdo>=${PHP_BASE_VERS}<5.3:../../databases/php-pdo
DEPENDS+=	php5-pdo_dblib>=${PHP_BASE_VERS}<5.3:../../databases/php-pdo_dblib
DEPENDS+=	php5-pdo_mysql>=${PHP_BASE_VERS}<5.3:../../databases/php-pdo_mysql
DEPENDS+=	php5-pdo_pgsql>=${PHP_BASE_VERS}<5.3:../../databases/php-pdo_pgsql
DEPENDS+=	php5-pdo_sqlite>=${PHP_BASE_VERS}<5.3:../../databases/php-pdo_sqlite
DEPENDS+=	php5-pgsql>=${PHP_BASE_VERS}<5.3:../../databases/php-pgsql
DEPENDS+=	php5-posix>=${PHP_BASE_VERS}<5.3:../../devel/php-posix
DEPENDS+=	php5-shmop>=${PHP_BASE_VERS}<5.3:../../devel/php-shmop
DEPENDS+=	php5-snmp>=${PHP_BASE_VERS}<5.3:../../net/php-snmp
DEPENDS+=	php5-soap>=${PHP_BASE_VERS}<5.3:../../net/php-soap
DEPENDS+=	php5-sockets>=${PHP_BASE_VERS}<5.3:../../net/php-sockets
DEPENDS+=	php5-sqlite>=${PHP_BASE_VERS}<5.3:../../databases/php-sqlite
DEPENDS+=	php5-sysvmsg>=${PHP_BASE_VERS}<5.3:../../devel/php-sysvmsg
DEPENDS+=	php5-sysvsem>=${PHP_BASE_VERS}<5.3:../../devel/php-sysvsem
DEPENDS+=	php5-sysvshm>=${PHP_BASE_VERS}<5.3:../../devel/php-sysvshm
DEPENDS+=	php5-wddx>=${PHP_BASE_VERS}<5.3:../../textproc/php-wddx
DEPENDS+=	php5-xsl>=${PHP_BASE_VERS}<5.3:../../textproc/php-xsl
DEPENDS+=	php5-xmlrpc>=${PHP_BASE_VERS}<5.3:../../net/php-xmlrpc
DEPENDS+=	php5-zip>=${PHP_BASE_VERS}<5.3:../../archivers/php-zip
DEPENDS+=	php5-zlib>=${PHP_BASE_VERS}<5.3:../../archivers/php-zlib

# PHP 5.2.x only extensions
DEPENDS+=	php5-dbase>=${PHP_BASE_VERS}<5.3:../../databases/php-dbase
DEPENDS+=	php5-dbx>=${PHP_BASE_VERS}<5.3:../../databases/php-dbx
DEPENDS+=	php5-mhash>=${PHP_BASE_VERS}<5.3:../../security/php-mhash
DEPENDS+=	php5-pspell>=${PHP_BASE_VERS}<5.3:../../textproc/php-pspell

META_PACKAGE=	yes

.include "../../lang/php5/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
