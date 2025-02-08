# $NetBSD: Makefile,v 1.6 2025/02/08 03:44:46 taca Exp $

DISTNAME=	Mail_mimeDecode-1.5.6
PKGREVISION=	1
CATEGORIES+=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to deal with decoding/interpreting of mime messages

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.6.0:../../mail/pear-Mail_Mime
CONFLICTS=	php-pear-Mail_Mime-[0-9]* \
		${PHP_PKG_PREFIX}-pear-Mail_Mime<1.6.0

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
