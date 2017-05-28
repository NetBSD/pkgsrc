# $NetBSD: Makefile,v 1.14 2017/05/28 11:33:17 taca Exp $

DISTNAME=	Mail-1.4.1
CATEGORIES=	mail

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails
LICENSE=	modified-bsd

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.4.1:../../net/pear-Net_SMTP

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
