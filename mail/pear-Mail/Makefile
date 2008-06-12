# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:35 joerg Exp $

DISTNAME=	Mail-1.1.14
PKGREVISION=	1
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP-[0-9]*:../../net/pear-Net_SMTP

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
