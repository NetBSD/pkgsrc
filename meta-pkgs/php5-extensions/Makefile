# $NetBSD: Makefile,v 1.1.1.1 2004/11/04 19:44:37 jdolecek Exp $

DISTNAME=	php-extensions-5.0
CATEGORIES=	meta-pkgs www php
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP5 HTML-embedded scripting language

# base PHP 5.x package
DEPENDS+=	php-5.0.*:../../lang/php5
DEPENDS+=	ap-php-5.0.*:../../www/ap-php

# extensions buildable with both PHP 4.x and PHP 5.x
DEPENDS+=	php-bcmath-5.0.*:../../math/php-bcmath
DEPENDS+=	php-bz2-5.0.*:../../archivers/php-bz2
DEPENDS+=	php-calendar-5.0.*:../../misc/php-calendar
DEPENDS+=	php-curl-5.0.*:../../www/php-curl
DEPENDS+=	php-dba-5.0.*:../../databases/php-dba
DEPENDS+=	php-dbase-5.0.*:../../databases/php-dbase
DEPENDS+=	php-exif-5.0.*:../../graphics/php-exif
DEPENDS+=	php-filepro-5.0.*:../../databases/php-filepro
DEPENDS+=	php-ftp-5.0.*:../../net/php-ftp
DEPENDS+=	php-gd-5.0.*:../../graphics/php-gd
DEPENDS+=	php-gettext-5.0.*:../../devel/php-gettext
DEPENDS+=	php-gmp-5.0.*:../../devel/php-gmp
DEPENDS+=	php-iconv-5.0.*:../../converters/php-iconv
DEPENDS+=	php-imap-5.0.*:../../mail/php-imap
DEPENDS+=	php-ldap-5.0.*:../../databases/php-ldap
DEPENDS+=	php-mbstring-5.0.*:../../misc/php-mbstring
DEPENDS+=	php-mcrypt-5.0.*:../../security/php-mcrypt
DEPENDS+=	php-mhash-5.0.*:../../security/php-mhash
DEPENDS+=	php-mssql-5.0.*:../../databases/php-mssql
DEPENDS+=	php-mysql-5.0.*:../../databases/php-mysql
DEPENDS+=	php-odbc-5.0.*:../../databases/php-odbc
DEPENDS+=	php-openssl-5.0.*:../../security/php-openssl
DEPENDS+=	php-pgsql-5.0.*:../../databases/php-pgsql
DEPENDS+=	php-posix-5.0.*:../../devel/php-posix
DEPENDS+=	php-shmop-5.0.*:../../devel/php-shmop
DEPENDS+=	php-snmp-5.0.*:../../net/php-snmp
DEPENDS+=	php-sockets-5.0.*:../../net/php-sockets
DEPENDS+=	php-sysvsem-5.0.*:../../devel/php-sysvsem
DEPENDS+=	php-sysvshm-5.0.*:../../devel/php-sysvshm
DEPENDS+=	php-wddx-5.0.*:../../textproc/php-wddx
DEPENDS+=	php-yp-5.0.*:../../net/php-yp
DEPENDS+=	php-zlib-5.0.*:../../archivers/php-zlib

# PHP 5.x-only extensions
DEPENDS+=	php-mysqli-5.0.*:../../databases/php5-mysqli
DEPENDS+=	php-sqlite-5.0.*:../../databases/php5-sqlite

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_BUILDLINK=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
