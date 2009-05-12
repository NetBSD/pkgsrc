# $NetBSD: Makefile,v 1.25 2009/05/12 12:27:19 martti Exp $

DISTNAME=	all_locales-${VER}-20071220
PKGNAME=	squirrelmail-locales-${VER}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail
LICENSE=	gnu-gpl-v2

VER=		1.4.13

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_TOOLS+=		pax
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && rm -rf en_US

do-install:
	cd ${WRKDIR} && \
		pax -rw -pp help images locale \
			${DESTDIR}${PREFIX}/share/squirrelmail

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
