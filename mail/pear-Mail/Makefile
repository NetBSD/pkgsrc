# $NetBSD: Makefile,v 1.13 2016/09/05 03:04:40 wen Exp $

DISTNAME=	Mail-1.3.0
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.4.1:../../net/pear-Net_SMTP

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
