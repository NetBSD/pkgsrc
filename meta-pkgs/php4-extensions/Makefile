# $NetBSD: Makefile,v 1.11 2005/09/28 19:17:16 rillig Exp $

DISTNAME=	php-extensions-4.4
CATEGORIES=	meta-pkgs www php4
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP4 HTML-embedded scripting language

# base PHP 4.x package
DEPENDS+=	php-4.4.*:../../www/php4
DEPENDS+=	ap-php-4.4.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php-bcmath-4.4.*:../../math/php-bcmath
DEPENDS+=	php-bz2-4.4.*:../../archivers/php-bz2
DEPENDS+=	php-calendar-4.4.*:../../misc/php-calendar
DEPENDS+=	php-curl-4.4.*:../../www/php-curl
DEPENDS+=	php-dba-4.4.*:../../databases/php-dba
DEPENDS+=	php-dbase-4.4.*:../../databases/php-dbase
DEPENDS+=	php-dbx-4.4.*:../../databases/php-dbx
DEPENDS+=	php-eaccelerator-4.4.*:../../www/php-eaccelerator
DEPENDS+=	php-exif-4.4.*:../../graphics/php-exif
DEPENDS+=	php-filepro-4.4.*:../../databases/php-filepro
DEPENDS+=	php-ftp-4.4.*:../../net/php-ftp
DEPENDS+=	php-gd-4.4.*:../../graphics/php-gd
DEPENDS+=	php-gettext-4.4.*:../../devel/php-gettext
DEPENDS+=	php-gmp-4.4.*:../../devel/php-gmp
DEPENDS+=	php-iconv-4.4.*:../../converters/php-iconv
DEPENDS+=	php-imap-4.4.*:../../mail/php-imap
DEPENDS+=	php-ldap-4.4.*:../../databases/php-ldap
DEPENDS+=	php-mbstring-4.4.*:../../misc/php-mbstring
DEPENDS+=	php-mcrypt-4.4.*:../../security/php-mcrypt
DEPENDS+=	php-mhash-4.4.*:../../security/php-mhash
DEPENDS+=	php-mssql-4.4.*:../../databases/php-mssql
DEPENDS+=	php-mysql-4.4.*:../../databases/php-mysql
DEPENDS+=	php-odbc-4.4.*:../../databases/php-odbc
DEPENDS+=	php-openssl-4.4.*:../../security/php-openssl
DEPENDS+=	php-pcntl-4.4.*:../../devel/php-pcntl
DEPENDS+=	php-pdflib-4.4.*:../../print/php-pdflib
DEPENDS+=	php-pgsql-4.4.*:../../databases/php-pgsql
DEPENDS+=	php-posix-4.4.*:../../devel/php-posix
DEPENDS+=	php-shmop-4.4.*:../../devel/php-shmop
DEPENDS+=	php-snmp-4.4.*:../../net/php-snmp
DEPENDS+=	php-sockets-4.4.*:../../net/php-sockets
DEPENDS+=	php-sysvsem-4.4.*:../../devel/php-sysvsem
DEPENDS+=	php-sysvshm-4.4.*:../../devel/php-sysvshm
DEPENDS+=	php-wddx-4.4.*:../../textproc/php-wddx
DEPENDS+=	php-yp-4.4.*:../../net/php-yp
DEPENDS+=	php-zip-4.4.*:../../archivers/php-zip
DEPENDS+=	php-zlib-4.4.*:../../archivers/php-zlib

# PHP 4.x-only extensions
DEPENDS+=	php-apc-4.4.*:../../www/php4-apc
DEPENDS+=	php-domxml-4.4.*:../../textproc/php4-domxml
DEPENDS+=	php-xslt-4.4.*:../../textproc/php4-xslt

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
