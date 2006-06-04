# $NetBSD: Makefile,v 1.4 2006/06/04 16:26:54 joerg Exp $

DISTNAME=	Mail-1.1.4
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=       ${PHP_PKG_PREFIX}-pear-Net_SMTP-[0-9]*:../../net/pear-Net_SMTP

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
