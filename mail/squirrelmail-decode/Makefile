# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 18:36:16 martti Exp $

DISTNAME=	squirrelmail-decode-1.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail

NO_BUILD=	yes

DEPENDS+=	php-iconv>=4.3.3:../../converters/php-iconv

do-install:
	${INSTALL_DATA} ${WRKSRC}/eastasia/*.php ${WRKSRC}/x-mac/*.php \
		${PREFIX}/share/squirrelmail/functions/decode

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
