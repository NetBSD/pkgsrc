# $NetBSD: Makefile,v 1.8 2008/03/04 17:57:20 jlam Exp $

DISTNAME=	squirrelmail-decode-1.2
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail
#LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.3:../../converters/php-iconv

do-install:
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX:Q}/share/squirrelmail/functions/decode
	${INSTALL_DATA} ${WRKSRC:Q}/eastasia/*.php ${WRKSRC:Q}/x-mac/*.php \
		${DESTDIR}${PREFIX:Q}/share/squirrelmail/functions/decode

.include "../../lang/php/phpversion.mk"
.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
