# $NetBSD: Makefile,v 1.3 1999/03/16 18:12:13 christos Exp $
#

DISTNAME=       zoularis-19990316
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/

WRKSRC=		${WRKDIR}/bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_PACKAGE=	This package is needed to compile the pkgtools

post-extract:
	@${ECHO} "Please read the instructions in ${WRKSRC}/README"

.include "../../mk/bsd.pkg.mk"
