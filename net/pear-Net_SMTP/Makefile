# $NetBSD: Makefile,v 1.7 2007/05/05 22:09:19 adrianp Exp $

DISTNAME=	Net_SMTP-1.2.6
CATEGORIES+=	net mail
PKGREVISION=	1

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.2:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
