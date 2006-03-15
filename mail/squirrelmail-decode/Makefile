# $NetBSD: Makefile,v 1.1.1.1.2.1 2006/03/15 12:07:55 salo Exp $

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
	${INSTALL_DATA} ${WRKSRC:Q}/eastasia/*.php ${WRKSRC:Q}/x-mac/*.php \
		${PREFIX:Q}/share/squirrelmail/functions/decode

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
