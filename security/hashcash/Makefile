# $NetBSD: Makefile,v 1.1.1.1 2004/03/29 19:01:34 tv Exp $
#

DISTNAME=		hashcash-0.28
CATEGORIES=		security
MASTER_SITES=		http://cypherspace.org/hashcash/source/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.hashcash.org/
COMMENT=		Hash collision based postage stamp

MAKE_FLAGS=		COPT="${CFLAGS} -Dunix"

USE_BUILDLINK3=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hashcash ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/hashcash.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
