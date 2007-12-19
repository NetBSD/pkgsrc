# $NetBSD: Makefile,v 1.22 2007/12/19 12:27:30 rillig Exp $

DISTNAME=	php-extensions-4.4
PKGREVISION=	9
CATEGORIES=	meta-pkgs www php4
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP4 HTML-embedded scripting language

# base PHP 4.x package
DEPENDS+=	php-4.4.*:../../www/php4
DEPENDS+=	${APACHE_PKG_PREFIX}-php4-4.4.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php4-apc-4.4.*:../../www/php-apc
DEPENDS+=	php4-bcmath-4.4.*:../../math/php-bcmath
DEPENDS+=	php4-bz2-4.4.*:../../archivers/php-bz2
DEPENDS+=	php4-calendar-4.4.*:../../misc/php-calendar
DEPENDS+=	php4-curl-4.4.*:../../www/php-curl
DEPENDS+=	php4-dba-4.4.*:../../databases/php-dba
DEPENDS+=	php4-dbase-4.4.*:../../databases/php-dbase
DEPENDS+=	php4-dbx-4.4.*:../../databases/php-dbx
DEPENDS+=	php4-eaccelerator-4.4.*:../../www/php-eaccelerator
DEPENDS+=	php4-exif-4.4.*:../../graphics/php-exif
DEPENDS+=	php4-filepro-4.4.*:../../databases/php-filepro
DEPENDS+=	php4-ftp-4.4.*:../../net/php-ftp
DEPENDS+=	php4-gd-4.4.*:../../graphics/php-gd
DEPENDS+=	php4-gettext-4.4.*:../../devel/php-gettext
DEPENDS+=	php4-gmp-4.4.*:../../devel/php-gmp
DEPENDS+=	php4-iconv-4.4.*:../../converters/php-iconv
DEPENDS+=	php4-imap-4.4.*:../../mail/php-imap
DEPENDS+=	php4-ldap-4.4.*:../../databases/php-ldap
DEPENDS+=	php4-mbstring-4.4.*:../../misc/php-mbstring
DEPENDS+=	php4-mcrypt-4.4.*:../../security/php-mcrypt
DEPENDS+=	php4-mhash-4.4.*:../../security/php-mhash
DEPENDS+=	php4-mssql-4.4.*:../../databases/php-mssql
DEPENDS+=	php4-mysql-4.4.*:../../databases/php-mysql
# odbc kills Apache1 on startup due to threaded unixodbc
# DEPENDS+=	php4-odbc-4.4.*:../../databases/php-odbc
DEPENDS+=	php4-pcntl-4.4.*:../../devel/php-pcntl
DEPENDS+=	php4-pdflib-4.4.*:../../print/php-pdflib
DEPENDS+=	php4-pgsql-4.4.*:../../databases/php-pgsql
DEPENDS+=	php4-posix-4.4.*:../../devel/php-posix
DEPENDS+=	php4-shmop-4.4.*:../../devel/php-shmop
DEPENDS+=	php4-snmp-4.4.*:../../net/php-snmp
DEPENDS+=	php4-sockets-4.4.*:../../net/php-sockets
DEPENDS+=	php4-sqlite-4.4.*:../../databases/php-sqlite
DEPENDS+=	php4-sysvsem-4.4.*:../../devel/php-sysvsem
DEPENDS+=	php4-sysvshm-4.4.*:../../devel/php-sysvshm
DEPENDS+=	php4-wddx-4.4.*:../../textproc/php-wddx
DEPENDS+=	php4-xmlrpc-4.4.*:../../net/php-xmlrpc
DEPENDS+=	php4-yp-4.4.*:../../net/php-yp
DEPENDS+=	php4-zip-4.4.*:../../archivers/php-zip
DEPENDS+=	php4-zlib-4.4.*:../../archivers/php-zlib

# PHP 4.x-only extensions
DEPENDS+=	php4-apc-4.4.*:../../www/php4-apc
DEPENDS+=	php4-domxml-4.4.*:../../textproc/php4-domxml
DEPENDS+=	php4-xslt-4.4.*:../../textproc/php4-xslt

META_PACKAGE=	yes

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
