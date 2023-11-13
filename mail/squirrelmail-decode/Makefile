# $NetBSD: Makefile,v 1.15 2023/11/13 16:01:45 taca Exp $

DISTNAME=	squirrelmail-decode-1.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Extra decoding library for SquirrelMail
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.3:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-squirrelmail>=1.4.23pre14998:../../mail/squirrelmail

do-install:
	${INSTALL_DATA_DIR} \
		${DESTDIR}${PREFIX}/${SMDIR}/functions/decode
	${INSTALL_DATA} ${WRKSRC}/eastasia/*.php ${WRKSRC}/x-mac/*.php \
		${DESTDIR}${PREFIX}/${SMDIR}/functions/decode

.include "../../mail/squirrelmail/squirrelmail.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
