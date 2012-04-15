# $NetBSD: Makefile,v 1.16 2012/04/15 22:01:02 wiz Exp $

DISTNAME=	Net_SMTP-1.6.1
CATEGORIES+=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
