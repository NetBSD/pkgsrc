# $NetBSD: Makefile,v 1.18 2019/07/03 07:28:23 nia Exp $

DISTNAME=	Net_Sieve-1.4.4
CATEGORIES+=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/Net_Sieve/
COMMENT=	PHP classes that handles talking to timsieved
LICENSE=	modified-bsd

CONFLICTS=	php-pear-Net_Sieve-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.0:../../net/pear-Net_Socket
# optional for DIGEST-MD5 and CRAM-MD5 SASL Authentication
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Auth_SASL>=1.0.0:../../mail/pear-Auth_SASL

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
