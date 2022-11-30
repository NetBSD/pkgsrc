# $NetBSD: Makefile,v 1.16 2022/11/30 15:13:18 taca Exp $

DISTNAME=	Mail-1.5.0
CATEGORIES=	mail

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails
LICENSE=	modified-bsd

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.10.0:../../net/pear-Net_SMTP

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
