# $NetBSD: Makefile,v 1.16 2025/05/19 15:37:17 taca Exp $

DISTNAME=	SOAP-0.14.0
CATEGORIES+=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	SOAP Client/Server for PHP

CONFLICTS=	php-pear-SOAP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.2:../../mail/pear-Mail_Mime
DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTTP_Request>=1.2:../../www/pear-HTTP_Request
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL>=1.0:../../net/pear-Net_URL
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_DIME>=0.3:../../net/pear-Net_DIME

PEAR_DIRRM_BASEDIR=	yes

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
