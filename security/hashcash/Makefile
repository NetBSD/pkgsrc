# $NetBSD: Makefile,v 1.3 2004/08/01 18:35:30 tv Exp $
#

DISTNAME=		hashcash-0.32
CATEGORIES=		security
MASTER_SITES=		http://www.hashcash.org/source/
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
