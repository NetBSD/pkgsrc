# $NetBSD: Makefile,v 1.7 2005/05/07 19:03:38 jdolecek Exp $

DISTNAME=	php-extensions-4.3
PKGREVISION=	5
CATEGORIES=	meta-pkgs www php
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP4 HTML-embedded scripting language

# base PHP 4.x package
DEPENDS+=	php-4.3.*:../../www/php4
DEPENDS+=	ap-php-4.3.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php-bcmath-4.3.*:../../math/php-bcmath
DEPENDS+=	php-bz2-4.3.*:../../archivers/php-bz2
DEPENDS+=	php-calendar-4.3.*:../../misc/php-calendar
DEPENDS+=	php-curl-4.3.*:../../www/php-curl
DEPENDS+=	php-dba-4.3.*:../../databases/php-dba
DEPENDS+=	php-dbase-4.3.*:../../databases/php-dbase
DEPENDS+=	php-dbx-4.3.*:../../databases/php-dbx
DEPENDS+=	php-eaccelerator-4.3.*:../../www/php-eaccelerator
DEPENDS+=	php-exif-4.3.*:../../graphics/php-exif
DEPENDS+=	php-filepro-4.3.*:../../databases/php-filepro
DEPENDS+=	php-ftp-4.3.*:../../net/php-ftp
DEPENDS+=	php-gd-4.3.*:../../graphics/php-gd
DEPENDS+=	php-gettext-4.3.*:../../devel/php-gettext
DEPENDS+=	php-gmp-4.3.*:../../devel/php-gmp
DEPENDS+=	php-iconv-4.3.*:../../converters/php-iconv
DEPENDS+=	php-imap-4.3.*:../../mail/php-imap
DEPENDS+=	php-ldap-4.3.*:../../databases/php-ldap
DEPENDS+=	php-mbstring-4.3.*:../../misc/php-mbstring
DEPENDS+=	php-mcrypt-4.3.*:../../security/php-mcrypt
DEPENDS+=	php-mhash-4.3.*:../../security/php-mhash
DEPENDS+=	php-mssql-4.3.*:../../databases/php-mssql
DEPENDS+=	php-mysql-4.3.*:../../databases/php-mysql
DEPENDS+=	php-odbc-4.3.*:../../databases/php-odbc
DEPENDS+=	php-openssl-4.3.*:../../security/php-openssl
DEPENDS+=	php-pdflib-4.3.*:../../print/php-pdflib
DEPENDS+=	php-pgsql-4.3.*:../../databases/php-pgsql
DEPENDS+=	php-posix-4.3.*:../../devel/php-posix
DEPENDS+=	php-shmop-4.3.*:../../devel/php-shmop
DEPENDS+=	php-snmp-4.3.*:../../net/php-snmp
DEPENDS+=	php-sockets-4.3.*:../../net/php-sockets
DEPENDS+=	php-sysvsem-4.3.*:../../devel/php-sysvsem
DEPENDS+=	php-sysvshm-4.3.*:../../devel/php-sysvshm
DEPENDS+=	php-wddx-4.3.*:../../textproc/php-wddx
DEPENDS+=	php-yp-4.3.*:../../net/php-yp
DEPENDS+=	php-zip-4.3.*:../../archivers/php-zip
DEPENDS+=	php-zlib-4.3.*:../../archivers/php-zlib

# PHP 4.x-only extensions
DEPENDS+=	php-apc-4.3.*:../../www/php4-apc
DEPENDS+=	php-domxml-4.3.*:../../textproc/php4-domxml
DEPENDS+=	php-xslt-4.3.*:../../textproc/php4-xslt

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
