# $NetBSD: Makefile,v 1.8 2005/07/18 07:04:29 martti Exp $
#

DISTNAME=	all_locales-${VER}-20050713
PKGNAME=	squirrelmail-locales-${VER}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail

VER=		1.4.5

NO_CONFIGURE=		# defined
USE_TOOLS+=		tar
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && ${RM} -rf en_US

do-install:
	cd ${WRKDIR} && ${TAR} -cf - help images locale | \
		${TAR} -xf - -C ${PREFIX}/share/squirrelmail/

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
