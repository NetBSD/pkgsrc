# $NetBSD: Makefile,v 1.21 2017/03/12 13:24:30 taca Exp $

DISTNAME=	Net_SMTP-1.7.3
CATEGORIES+=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
