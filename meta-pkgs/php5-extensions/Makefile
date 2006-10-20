# $NetBSD: Makefile,v 1.19 2006/10/20 21:56:38 jdolecek Exp $

DISTNAME=	php-extensions-5.1
PKGREVISION=	5
CATEGORIES=	meta-pkgs www php5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP5 HTML-embedded scripting language

# base PHP 5.x package
DEPENDS+=	php-5.1.*:../../lang/php5
DEPENDS+=	${APACHE_PKG_PREFIX}-php5-5.1.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php5-bcmath-5.1.*:../../math/php-bcmath
DEPENDS+=	php5-bz2-5.1.*:../../archivers/php-bz2
DEPENDS+=	php5-calendar-5.1.*:../../misc/php-calendar
DEPENDS+=	php5-curl-5.1.*:../../www/php-curl
DEPENDS+=	php5-dba-5.1.*:../../databases/php-dba
DEPENDS+=	php5-dbase-5.1.*:../../databases/php-dbase
DEPENDS+=	php5-dbx-5.1.*:../../databases/php-dbx
# eaccelerator doesn't compile/work with 5.1
# DEPENDS+=	php-eaccelerator-5.1.*:../../www/php-eaccelerator
DEPENDS+=	php5-exif-5.1.*:../../graphics/php-exif
DEPENDS+=	php5-filepro-5.1.*:../../databases/php-filepro
DEPENDS+=	php5-ftp-5.1.*:../../net/php-ftp
DEPENDS+=	php5-gd-5.1.*:../../graphics/php-gd
DEPENDS+=	php5-gettext-5.1.*:../../devel/php-gettext
DEPENDS+=	php5-gmp-5.1.*:../../devel/php-gmp
DEPENDS+=	php5-iconv-5.1.*:../../converters/php-iconv
DEPENDS+=	php5-imap-5.1.*:../../mail/php-imap
DEPENDS+=	php5-ldap-5.1.*:../../databases/php-ldap
DEPENDS+=	php5-mbstring-5.1.*:../../misc/php-mbstring
DEPENDS+=	php5-mcrypt-5.1.*:../../security/php-mcrypt
DEPENDS+=	php5-mhash-5.1.*:../../security/php-mhash
DEPENDS+=	php5-mssql-5.1.*:../../databases/php-mssql
DEPENDS+=	php5-mysql-5.1.*:../../databases/php-mysql
# odbc kills Apache1 on startup due to threaded unixodbc
# DEPENDS+=	php5-odbc-5.1.*:../../databases/php-odbc
DEPENDS+=	php5-pcntl-5.1.*:../../devel/php-pcntl
DEPENDS+=	php5-pdflib-5.1.*:../../print/php-pdflib
DEPENDS+=	php5-pgsql-5.1.*:../../databases/php-pgsql
DEPENDS+=	php5-posix-5.1.*:../../devel/php-posix
DEPENDS+=	php5-shmop-5.1.*:../../devel/php-shmop
DEPENDS+=	php5-snmp-5.1.*:../../net/php-snmp
DEPENDS+=	php5-sockets-5.1.*:../../net/php-sockets
DEPENDS+=	php5-sqlite-5.1.*:../../databases/php-sqlite
DEPENDS+=	php5-sysvsem-5.1.*:../../devel/php-sysvsem
DEPENDS+=	php5-sysvshm-5.1.*:../../devel/php-sysvshm
DEPENDS+=	php5-wddx-5.1.*:../../textproc/php-wddx
DEPENDS+=	php5-xmlrpc-5.1.*:../../net/php-xmlrpc
DEPENDS+=	php5-zip-5.1.*:../../archivers/php-zip
DEPENDS+=	php5-zlib-5.1.*:../../archivers/php-zlib

# PHP 5.x-only extensions
DEPENDS+=	php5-dom-5.1.*:../../textproc/php5-dom
DEPENDS+=	php5-mysqli-5.1.*:../../databases/php5-mysqli
DEPENDS+=	php5-soap-5.1.*:../../net/php5-soap
DEPENDS+=	php5-xsl-5.1.*:../../textproc/php5-xsl
DEPENDS+=	php5-pdo-5.1.*:../../databases/php-pdo
DEPENDS+=	php5-pdo_dblib-5.1.*:../../databases/php-pdo_dblib
DEPENDS+=	php5-pdo_mysql-5.1.*:../../databases/php-pdo_mysql
DEPENDS+=	php5-pdo_odbc-5.1.*:../../databases/php-pdo_odbc
DEPENDS+=	php5-pdo_pgsql-5.1.*:../../databases/php-pdo_pgsql
DEPENDS+=	php5-pdo_sqlite-5.1.*:../../databases/php-pdo_sqlite

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty


.include "../../mk/apachever.mk"
.include "../../mk/bsd.pkg.mk"
