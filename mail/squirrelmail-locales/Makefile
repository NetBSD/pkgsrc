# $NetBSD: Makefile,v 1.29 2023/11/13 16:02:03 taca Exp $

DISTNAME=	all_locales-${VER}-20090526
PKGNAME=	${PHP_PKG_PREFIX}-squirrelmail-locales-${VER}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail
LICENSE=	gnu-gpl-v2

VER=		1.4.18

NO_CONFIGURE=		yes
USE_TOOLS+=		pax
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && rm -rf en_US

do-install:
	cd ${WRKDIR} && \
		pax -rw -pp help images locale \
			${DESTDIR}${PREFIX}/${SMDIR}

.include "../../mail/squirrelmail/squirrelmail.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
