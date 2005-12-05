# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:59 rillig Exp $

DISTNAME=	bchunk-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hes.iki.fi/bchunk/

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://hes.iki.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

MAKE_FLAGS+=	CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${PREFIX}/man/man1/bchunk.1

.include "../../mk/bsd.pkg.mk"
