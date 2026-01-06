# $NetBSD: Makefile,v 1.35 2026/01/06 15:07:32 taca Exp $

DISTNAME=	Net_SMTP-1.12.2
CATEGORIES+=	net mail
DIST_SUBDIR=	pear/20231026

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface
LICENSE=	2-clause-bsd

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
