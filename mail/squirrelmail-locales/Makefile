# $NetBSD: Makefile,v 1.28 2012/10/08 12:19:32 asau Exp $

DISTNAME=	all_locales-${VER}-20090526
PKGNAME=	squirrelmail-locales-${VER}
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
			${DESTDIR}${PREFIX}/share/squirrelmail

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
