# $NetBSD: Makefile,v 1.6 2012/06/16 02:59:48 taca Exp $
#

MODNAME=		suhosin
DISTNAME=		suhosin-${PECL_VERSION}
PECL_VERSION=		0.9.33
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES=		www
MASTER_SITES=		http://download.suhosin.org/

MAINTAINER=		cg@cgall.de
HOMEPAGE=		http://www.hardened-php.net/suhosin/index.html
COMMENT=		Advanced protection system for PHP installations

PKG_DESTDIR_SUPPORT=	user-destdir

# There is no patch for PHP 5.4 yet(?). 
PHP_VERSIONS_ACCEPTED=	52 53

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
