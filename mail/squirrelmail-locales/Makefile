# $NetBSD: Makefile,v 1.15.2.2 2006/08/14 17:14:12 ghen Exp $

DISTNAME=	all_locales-${VER}-20060811
PKGNAME=	squirrelmail-locales-${VER}
#PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail

VER=		1.4.8

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
