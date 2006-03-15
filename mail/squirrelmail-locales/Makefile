# $NetBSD: Makefile,v 1.9.2.1 2006/03/15 12:07:55 salo Exp $
#

DISTNAME=	all_locales-${VER}-20060221
PKGNAME=	squirrelmail-locales-${VER}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail

VER=		1.4.6

NO_CONFIGURE=		yes
USE_TOOLS+=		tar
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR:Q}/help && ${RM} -rf en_US

do-install:
	cd ${WRKDIR:Q} && ${TAR} -cf - help images locale | \
		${TAR} -xf - -C ${PREFIX:Q}/share/squirrelmail/

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
