# $NetBSD: Makefile,v 1.12 2012/10/08 12:19:25 asau Exp $

DISTNAME=	Mail-1.2.0
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP-[0-9]*:../../net/pear-Net_SMTP

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
