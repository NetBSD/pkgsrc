# $NetBSD: Makefile,v 1.3 2004/11/28 10:21:48 jdolecek Exp $

DISTNAME=	Net_Socket-1.0.2
CATEGORIES+=	net

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide Network Socket Interface

.include "../../lang/php/pear.mk"

# used to be bundled before PHP 5.x
.if ${_PHP_VERSION} < 5
PKG_SKIP_REASON=	"${PKGBASE} is part of PHP${_PHP_VERSION}"
.endif

.include "../../mk/bsd.pkg.mk"
