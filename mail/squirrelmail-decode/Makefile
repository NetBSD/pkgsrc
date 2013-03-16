# $NetBSD: Makefile,v 1.13 2013/03/16 07:21:21 obache Exp $

DISTNAME=	squirrelmail-decode-1.2
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail
LICENSE=	gnu-gpl-v2

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
