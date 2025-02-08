# $NetBSD: Makefile,v 1.17 2025/02/08 03:44:48 taca Exp $

DISTNAME=	squirrelmail-decode-1.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-squirrelmail>=1.4.23pre14997:../../mail/squirrelmail

do-install:
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${SMDIR}/functions/decode
	${INSTALL_DATA} ${WRKSRC}/eastasia/*.php ${WRKSRC}/x-mac/*.php \
		${DESTDIR}${PREFIX}/${SMDIR}/functions/decode

.include "../../mail/squirrelmail/squirrelmail.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
