# $NetBSD: Makefile,v 1.19 2007/01/10 14:24:26 martti Exp $

DISTNAME=	all_locales-${VER}-20070106
PKGNAME=	squirrelmail-locales-${VER}
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail

VER=		1.4.9

NO_CONFIGURE=		yes
USE_TOOLS+=		tar
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR:Q}/help && rm -rf en_US

do-install:
	cd ${WRKDIR:Q} && tar -cf - help images locale | \
		tar -xf - -C ${PREFIX:Q}/share/squirrelmail/

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
