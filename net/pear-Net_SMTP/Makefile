# $NetBSD: Makefile,v 1.2 2004/11/28 10:21:48 jdolecek Exp $

DISTNAME=	Net_SMTP-1.2.6
CATEGORIES+=	net mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

.include "../../lang/php/pear.mk"

# used to be bundled before PHP 5.x
.if ${_PHP_VERSION} < 5
PKG_SKIP_REASON=	"${PKGBASE} is part of PHP${_PHP_VERSION}"
.endif

.include "../../mk/bsd.pkg.mk"
