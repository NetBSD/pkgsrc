# $NetBSD: Makefile,v 1.8 2006/03/22 22:50:33 tv Exp $
#

DISTNAME=		hashcash-1.13
CATEGORIES=		security
MASTER_SITES=		http://www.hashcash.org/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@NetBSD.org
HOMEPAGE=		http://www.hashcash.org/
COMMENT=		Hash collision based postage stamp


.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-Dunix
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hashcash ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/hashcash.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
