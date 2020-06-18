# $NetBSD: Makefile,v 1.25 2020/06/18 16:54:25 taca Exp $

DISTNAME=	Net_SMTP-1.9.1
CATEGORIES+=	net mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface
LICENSE=	2-clause-bsd

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
