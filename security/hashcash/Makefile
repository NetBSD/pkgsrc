# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:32 jlam Exp $
#

DISTNAME=		hashcash-1.13
CATEGORIES=		security
MASTER_SITES=		http://www.hashcash.org/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.hashcash.org/
COMMENT=		Hash collision based postage stamp


.include "../../mk/bsd.prefs.mk"

CFLAGS+=		-Dunix
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hashcash ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/hashcash.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
