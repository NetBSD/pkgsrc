# $NetBSD: Makefile,v 1.6 2010/02/03 11:48:04 obache Exp $

DISTNAME=	Net_Sieve-1.1.7
CATEGORIES+=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Net_Sieve/
COMMENT=	PHP classes that handles talking to timsieved
LICENSE=	modified-bsd

CONFLICTS=	php-pear-Net_Sieve-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.0:../../net/pear-Net_Socket

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
