# $NetBSD: Makefile,v 1.10 1999/03/08 10:53:56 agc Exp $
#

DISTNAME=	readline-2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

SCRIPTS_ENV+=	PLIST_SRC="${PLIST_SRC}"

do-build:
	(cd ${WRKSRC}; ${MAKE} LIB=readline)
	(cd ${WRKSRC}; ${MAKE} LIB=history)

.include "../../mk/bsd.pkg.mk"
