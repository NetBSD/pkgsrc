# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:08 jlam Exp $
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

NO_CONFIGURE=		# defined
PKGSRC_USE_TOOLS+=	tar
INSTALLATION_DIRS=	share/squirrelmail

WRKSRC=		${WRKDIR}

do-build:
	cd ${WRKDIR}/help && ${RM} -rf en_US

do-install:
	cd ${WRKDIR} && ${TAR} -cf - help images locale | \
		${TAR} -xf - -C ${PREFIX}/share/squirrelmail/

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
