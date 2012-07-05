# $NetBSD: Makefile,v 1.2 2012/07/05 09:48:49 cheusov Exp $

DISTNAME=	${PHP_PKG_PREFIX}-extensions-${PHP_BASE_VERS}
CATEGORIES=	meta-pkgs www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.php.net/
COMMENT=	"meta-package" for the PHP 5.4 HTML-embedded scripting language

DEPENDS+=	php>=${PHP_BASE_VERS}<${NEXT_VERS}:${PHPPKGSRCDIR}
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=${PHP_BASE_VERS}<${NEXT_VERS}:../../www/ap-php
DEPENDS+=	${PHP_PKG_PREFIX}-fpm>=${PHP_BASE_VERS}<${NEXT_VERS}:../../www/php-fpm

DEPENDS+=	${PHP_PKG_PREFIX}-bcmath>=${PHP_BASE_VERS}<${NEXT_VERS}:../../math/php-bcmath
DEPENDS+=	${PHP_PKG_PREFIX}-bz2>=${PHP_BASE_VERS}<${NEXT_VERS}:../../archivers/php-bz2
DEPENDS+=	${PHP_PKG_PREFIX}-calendar>=${PHP_BASE_VERS}<${NEXT_VERS}:../../time/php-calendar
DEPENDS+=	${PHP_PKG_PREFIX}-curl>=${PHP_BASE_VERS}<${NEXT_VERS}:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-dba>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-dba
DEPENDS+=	${PHP_PKG_PREFIX}-dom>=${PHP_BASE_VERS}<${NEXT_VERS}:../../textproc/php-dom
DEPENDS+=	${PHP_PKG_PREFIX}-enchant>=${PHP_BASE_VERS}:../../textproc/php-enchant
DEPENDS+=	${PHP_PKG_PREFIX}-exif>=${PHP_BASE_VERS}<${NEXT_VERS}:../../graphics/php-exif
DEPENDS+=	${PHP_PKG_PREFIX}-ftp>=${PHP_BASE_VERS}<${NEXT_VERS}:../../net/php-ftp
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=${PHP_BASE_VERS}<${NEXT_VERS}:../../graphics/php-gd
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-gettext
DEPENDS+=	${PHP_PKG_PREFIX}-gmp>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-gmp
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}<${NEXT_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=${PHP_BASE_VERS}<${NEXT_VERS}:../../mail/php-imap
DEPENDS+=	${PHP_PKG_PREFIX}-intl>=5.3.8:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}<${NEXT_VERS}:../../textproc/php-json
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}<${NEXT_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=${PHP_BASE_VERS}<${NEXT_VERS}:../../security/php-mcrypt
DEPENDS+=	${PHP_PKG_PREFIX}-mssql>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-mssql
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-mysqli>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-mysqli
# broken
# DEPENDS+=	${PHP_PKG_PREFIX}-odbc>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-odbc
DEPENDS+=	${PHP_PKG_PREFIX}-pcntl>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-pcntl
DEPENDS+=	${PHP_PKG_PREFIX}-pdo>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pdo
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_dblib>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pdo_dblib
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pdo_mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pdo_pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pdo_sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=${PHP_BASE_VERS}<${NEXT_VERS}:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-posix>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-posix
DEPENDS+=	${PHP_PKG_PREFIX}-pspell>=${PHP_BASE_VERS}<${NEXT_VERS}:../../textproc/php-pspell
DEPENDS+=	${PHP_PKG_PREFIX}-shmop>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-shmop
DEPENDS+=	${PHP_PKG_PREFIX}-snmp>=${PHP_BASE_VERS}<${NEXT_VERS}:../../net/php-snmp
DEPENDS+=	${PHP_PKG_PREFIX}-soap>=${PHP_BASE_VERS}<${NEXT_VERS}:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=${PHP_BASE_VERS}<${NEXT_VERS}:../../net/php-sockets
DEPENDS+=	${PHP_PKG_PREFIX}-sysvmsg>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-sysvmsg
DEPENDS+=	${PHP_PKG_PREFIX}-sysvsem>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-sysvsem
DEPENDS+=	${PHP_PKG_PREFIX}-sysvshm>=${PHP_BASE_VERS}<${NEXT_VERS}:../../devel/php-sysvshm
DEPENDS+=	${PHP_PKG_PREFIX}-tidy>=${PHP_BASE_VERS}<${NEXT_VERS}:../../www/php-tidy
DEPENDS+=	${PHP_PKG_PREFIX}-wddx>=${PHP_BASE_VERS}<${NEXT_VERS}:../../textproc/php-wddx
DEPENDS+=	${PHP_PKG_PREFIX}-xmlrpc>=${PHP_BASE_VERS}<${NEXT_VERS}:../../net/php-xmlrpc
DEPENDS+=	${PHP_PKG_PREFIX}-xsl>=${PHP_BASE_VERS}<${NEXT_VERS}:../../textproc/php-xsl
DEPENDS+=	${PHP_PKG_PREFIX}-zip>=${PHP_BASE_VERS}<${NEXT_VERS}:../../archivers/php-zip
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=${PHP_BASE_VERS}<${NEXT_VERS}:../../archivers/php-zlib

NEXT_VERS=		5.5
PHP_VERSIONS_ACCEPTED=	54
META_PACKAGE=		yes

.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
