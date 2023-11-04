# $NetBSD: Makefile,v 1.31 2023/11/04 15:21:26 taca Exp $

DISTNAME=	Net_SMTP-1.11.1
CATEGORIES+=	net mail
DIST_SUBDIR=	pear/20231026

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface
LICENSE=	2-clause-bsd

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
