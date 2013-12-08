# $NetBSD: Makefile,v 1.10 2013/12/08 22:34:33 joerg Exp $
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

# There is no patch for PHP 5.4 yet(?).
PHP_VERSIONS_ACCEPTED=	53

CONFIGURE_ARGS=		--enable-${MODNAME}

.include "../../lang/php/ext.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang) && ${_PHP_VERSION} == "53"
CFLAGS+=	-Wno-error=return-type
.endif

.include "../../mk/bsd.pkg.mk"
