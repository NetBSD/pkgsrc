# $NetBSD: Makefile,v 1.10 2009/11/30 06:16:56 taca Exp $

DISTNAME=	Mail-1.1.14
PKGREVISION=	2
CATEGORIES=	mail

CONFLICTS=	php-pear-Mail-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_SMTP-[0-9]*:../../net/pear-Net_SMTP

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Mail
COMMENT=	PHP Class that provides multiple interfaces for sending emails

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
