# $NetBSD: Makefile,v 1.1.1.1 2010/02/06 16:14:21 taca Exp $

DISTNAME=	Mail_mimeDecode-1.5.1
CATEGORIES+=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to deal with decoding/interpreting of mime messages

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Mail_Mime>=1.6.0:../../mail/pear-Mail_Mime
CONFLICTS=	php-pear-Mail_Mime-[0-9]* \
		${PHP_PKG_PREFIX}-pear-Mail_Mime<1.6.0

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
