# $NetBSD: Makefile,v 1.7 2007/10/30 19:31:41 martti Exp $

DISTNAME=	squirrelmail-decode-1.2
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail
#LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.3:../../converters/php-iconv

do-install:
	${INSTALL_DATA} ${WRKSRC:Q}/eastasia/*.php ${WRKSRC:Q}/x-mac/*.php \
		${PREFIX:Q}/share/squirrelmail/functions/decode

.include "../../lang/php/phpversion.mk"
.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
