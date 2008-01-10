# $NetBSD: Makefile,v 1.22 2008/01/10 20:52:59 adam Exp $

DISTNAME=	all_locales-${VER}-20071220
PKGNAME=	squirrelmail-locales-${VER}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail
#LICENSE=	gnu-gpl-v2

VER=		1.4.13

NO_CONFIGURE=		yes
USE_TOOLS+=		tar
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && rm -rf en_US

do-install:
	cd ${WRKDIR} && \
		pax -rw -pp help images locale ${PREFIX}/share/squirrelmail

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
