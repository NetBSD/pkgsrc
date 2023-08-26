# $NetBSD: Makefile,v 1.17 2023/08/26 07:15:21 taca Exp $

DISTNAME=	Mail-1.5.1
CATEGORIES=	mail

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails
LICENSE=	modified-bsd

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP>=1.10.0:../../net/pear-Net_SMTP

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
