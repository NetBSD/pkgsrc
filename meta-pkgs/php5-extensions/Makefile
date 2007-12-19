# $NetBSD: Makefile,v 1.21 2007/12/19 12:27:30 rillig Exp $

DISTNAME=	php-extensions-5.2
#PKGREVISION=	1
CATEGORIES=	meta-pkgs www php5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP5 HTML-embedded scripting language

# base PHP 5.x package
DEPENDS+=	php-5.2.*:../../lang/php5
DEPENDS+=	${APACHE_PKG_PREFIX}-php5-5.2.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php5-apc-5.2.*:../../www/php-apc
DEPENDS+=	php5-bcmath-5.2.*:../../math/php-bcmath
DEPENDS+=	php5-bz2-5.2.*:../../archivers/php-bz2
DEPENDS+=	php5-calendar-5.2.*:../../misc/php-calendar
DEPENDS+=	php5-curl-5.2.*:../../www/php-curl
DEPENDS+=	php5-dba-5.2.*:../../databases/php-dba
DEPENDS+=	php5-dbase-5.2.*:../../databases/php-dbase
DEPENDS+=	php5-dbx-5.2.*:../../databases/php-dbx
DEPENDS+=	php5-eaccelerator-5.2.*:../../www/php-eaccelerator
DEPENDS+=	php5-exif-5.2.*:../../graphics/php-exif
# filepro extension removed in 5.2
# DEPENDS+=	php5-filepro-5.2.*:../../databases/php-filepro
DEPENDS+=	php5-ftp-5.2.*:../../net/php-ftp
DEPENDS+=	php5-gd-5.2.*:../../graphics/php-gd
DEPENDS+=	php5-gettext-5.2.*:../../devel/php-gettext
DEPENDS+=	php5-gmp-5.2.*:../../devel/php-gmp
DEPENDS+=	php5-iconv-5.2.*:../../converters/php-iconv
DEPENDS+=	php5-imap-5.2.*:../../mail/php-imap
DEPENDS+=	php5-json-5.2.*:../../textproc/php-json
DEPENDS+=	php5-ldap-5.2.*:../../databases/php-ldap
DEPENDS+=	php5-mbstring-5.2.*:../../misc/php-mbstring
DEPENDS+=	php5-mcrypt-5.2.*:../../security/php-mcrypt
DEPENDS+=	php5-mhash-5.2.*:../../security/php-mhash
DEPENDS+=	php5-mssql-5.2.*:../../databases/php-mssql
DEPENDS+=	php5-mysql-5.2.*:../../databases/php-mysql
# odbc kills Apache1 on startup due to threaded unixodbc
# DEPENDS+=	php5-odbc-5.2.*:../../databases/php-odbc
DEPENDS+=	php5-pcntl-5.2.*:../../devel/php-pcntl
DEPENDS+=	php5-pdflib-5.2.*:../../print/php-pdflib
DEPENDS+=	php5-pgsql-5.2.*:../../databases/php-pgsql
DEPENDS+=	php5-posix-5.2.*:../../devel/php-posix
DEPENDS+=	php5-shmop-5.2.*:../../devel/php-shmop
DEPENDS+=	php5-snmp-5.2.*:../../net/php-snmp
DEPENDS+=	php5-sockets-5.2.*:../../net/php-sockets
DEPENDS+=	php5-sqlite-5.2.*:../../databases/php-sqlite
DEPENDS+=	php5-sysvsem-5.2.*:../../devel/php-sysvsem
DEPENDS+=	php5-sysvshm-5.2.*:../../devel/php-sysvshm
DEPENDS+=	php5-wddx-5.2.*:../../textproc/php-wddx
DEPENDS+=	php5-xmlrpc-5.2.*:../../net/php-xmlrpc
DEPENDS+=	php5-zip-5.2.*:../../archivers/php-zip
DEPENDS+=	php5-zlib-5.2.*:../../archivers/php-zlib

# PHP 5.x-only extensions
DEPENDS+=	php5-dom-5.2.*:../../textproc/php5-dom
DEPENDS+=	php5-mysqli-5.2.*:../../databases/php5-mysqli
DEPENDS+=	php5-soap-5.2.*:../../net/php5-soap
DEPENDS+=	php5-xsl-5.2.*:../../textproc/php5-xsl
DEPENDS+=	php5-pdo-5.2.*:../../databases/php-pdo
DEPENDS+=	php5-pdo_dblib-5.2.*:../../databases/php-pdo_dblib
DEPENDS+=	php5-pdo_mysql-5.2.*:../../databases/php-pdo_mysql
# odbc kills Apache1 on startup due to threaded unixodbc
# DEPENDS+=	php5-pdo_odbc-5.2.*:../../databases/php-pdo_odbc
DEPENDS+=	php5-pdo_pgsql-5.2.*:../../databases/php-pdo_pgsql
DEPENDS+=	php5-pdo_sqlite-5.2.*:../../databases/php-pdo_sqlite

META_PACKAGE=	yes

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
