# $NetBSD: Makefile,v 1.9 2006/11/06 22:06:35 jdolecek Exp $

MODNAME=		filepro
CATEGORIES+=		databases
COMMENT=		PHP extension for read-only filePro database access

CONFLICTS=	php-filepro-[0-9]*

# filepro extension removed in PHP 5.2.0, no replacement in PECL yet
PHP_VERSIONS_ACCEPTED=  4

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
