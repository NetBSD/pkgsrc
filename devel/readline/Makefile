# $NetBSD: Makefile,v 1.9 1998/07/14 15:55:38 agc Exp $
#

DISTNAME=	readline-2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

SCRIPTS_ENV+=	PLIST_SRC="${PLIST_SRC}"

do-build:
	(cd ${WRKSRC}; make LIB=readline)
	(cd ${WRKSRC}; make LIB=history)

.include "../../mk/bsd.pkg.mk"
