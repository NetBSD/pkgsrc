# $NetBSD: Makefile,v 1.8 2008/04/30 19:32:34 adrianp Exp $

DISTNAME=	Net_SMTP-1.3.0
CATEGORIES+=	net mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
