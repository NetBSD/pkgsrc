# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:27 tv Exp $
#

DISTNAME=	all_locales-${VER}-20050122
PKGNAME=	squirrelmail-locales-${VER}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Locale package for SquirrelMail

VER=		1.4.4

NO_CONFIGURE=	# defined

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && ${RM} -rf en_US

do-install:
	cd ${WRKDIR} && ${TAR} -cf - help images locale | \
		${TAR} -xf - -C ${PREFIX}/share/squirrelmail/

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
