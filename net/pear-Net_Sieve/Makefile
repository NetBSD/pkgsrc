# $NetBSD: Makefile,v 1.4 2007/05/05 22:09:19 adrianp Exp $

DISTNAME=	Net_Sieve-1.1.1
CATEGORIES+=	net
PKGREVISION=	1

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Net_Sieve/
COMMENT=	PHP classes that handles talking to timsieved

CONFLICTS=	php-pear-Net_Sieve-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.0:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
