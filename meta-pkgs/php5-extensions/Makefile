# $NetBSD: Makefile,v 1.16 2006/01/24 07:32:21 wiz Exp $

DISTNAME=	php-extensions-5.1
PKGREVISION=	# empty
PKGREVISION=	2
CATEGORIES=	meta-pkgs www php5
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP5 HTML-embedded scripting language

# base PHP 5.x package
DEPENDS+=	php-5.1.*:../../lang/php5
DEPENDS+=	ap-php-5.1.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php-bcmath-5.1.*:../../math/php-bcmath
DEPENDS+=	php-bz2-5.1.*:../../archivers/php-bz2
DEPENDS+=	php-calendar-5.1.*:../../misc/php-calendar
DEPENDS+=	php-curl-5.1.*:../../www/php-curl
DEPENDS+=	php-dba-5.1.*:../../databases/php-dba
DEPENDS+=	php-dbase-5.1.*:../../databases/php-dbase
DEPENDS+=	php-dbx-5.1.*:../../databases/php-dbx
# eaccelerator doesn't compile/work with 5.1
# DEPENDS+=	php-eaccelerator-5.1.*:../../www/php-eaccelerator
DEPENDS+=	php-exif-5.1.*:../../graphics/php-exif
DEPENDS+=	php-filepro-5.1.*:../../databases/php-filepro
DEPENDS+=	php-ftp-5.1.*:../../net/php-ftp
DEPENDS+=	php-gd-5.1.*:../../graphics/php-gd
DEPENDS+=	php-gettext-5.1.*:../../devel/php-gettext
DEPENDS+=	php-gmp-5.1.*:../../devel/php-gmp
DEPENDS+=	php-iconv-5.1.*:../../converters/php-iconv
DEPENDS+=	php-imap-5.1.*:../../mail/php-imap
DEPENDS+=	php-ldap-5.1.*:../../databases/php-ldap
DEPENDS+=	php-mbstring-5.1.*:../../misc/php-mbstring
DEPENDS+=	php-mcrypt-5.1.*:../../security/php-mcrypt
DEPENDS+=	php-mhash-5.1.*:../../security/php-mhash
DEPENDS+=	php-mssql-5.1.*:../../databases/php-mssql
DEPENDS+=	php-mysql-5.1.*:../../databases/php-mysql
DEPENDS+=	php-odbc-5.1.*:../../databases/php-odbc
DEPENDS+=	php-pcntl-5.1.*:../../devel/php-pcntl
DEPENDS+=	php-pdflib-5.1.*:../../print/php-pdflib
DEPENDS+=	php-pgsql-5.1.*:../../databases/php-pgsql
DEPENDS+=	php-posix-5.1.*:../../devel/php-posix
DEPENDS+=	php-shmop-5.1.*:../../devel/php-shmop
DEPENDS+=	php-snmp-5.1.*:../../net/php-snmp
DEPENDS+=	php-sockets-5.1.*:../../net/php-sockets
DEPENDS+=	php-sqlite-5.1.*:../../databases/php-sqlite
DEPENDS+=	php-sysvsem-5.1.*:../../devel/php-sysvsem
DEPENDS+=	php-sysvshm-5.1.*:../../devel/php-sysvshm
DEPENDS+=	php-wddx-5.1.*:../../textproc/php-wddx
DEPENDS+=	php-xmlrpc-5.1.*:../../net/php-xmlrpc
DEPENDS+=	php-zip-5.1.*:../../archivers/php-zip
DEPENDS+=	php-zlib-5.1.*:../../archivers/php-zlib

# PHP 5.x-only extensions
DEPENDS+=	php-dom-5.1.*:../../textproc/php5-dom
DEPENDS+=	php-mysqli-5.1.*:../../databases/php5-mysqli
DEPENDS+=	php-soap-5.1.*:../../net/php5-soap
DEPENDS+=	php-xsl-5.1.*:../../textproc/php5-xsl
DEPENDS+=	php-pdo-5.1.*:../../databases/php-pdo
DEPENDS+=	php-pdo_dblib-5.1.*:../../databases/php-pdo_dblib
DEPENDS+=	php-pdo_mysql-5.1.*:../../databases/php-pdo_mysql
DEPENDS+=	php-pdo_odbc-5.1.*:../../databases/php-pdo_odbc
DEPENDS+=	php-pdo_pgsql-5.1.*:../../databases/php-pdo_pgsql
DEPENDS+=	php-pdo_sqlite-5.1.*:../../databases/php-pdo_sqlite

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
