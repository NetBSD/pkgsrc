# $NetBSD: Makefile,v 1.3 2006/06/02 18:27:56 joerg Exp $

DISTNAME=	Mail-1.1.4
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]

DEPENDS+=       ${PHP_PKG_PREFIX}-pear-Net_SMTP-[0-9]*:../../net/pear-Net_SMTP

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
