# $NetBSD: Makefile,v 1.6 1998/04/17 09:37:24 agc Exp $
#

DISTNAME=	readline-2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

MAN3=		readline.3

SCRIPTS_ENV+=	PLIST_SRC="${PLIST_SRC}"

do-build:
	(cd ${WRKSRC}; make LIB=readline)
	(cd ${WRKSRC}; make LIB=history)

post-install:
	@${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
