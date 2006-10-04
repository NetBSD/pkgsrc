# $NetBSD: Makefile,v 1.8 2006/10/04 21:59:34 wiz Exp $

DISTNAME=	bchunk-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://he.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

MAKE_FLAGS+=	CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${PREFIX}/man/man1/bchunk.1

.include "../../mk/bsd.pkg.mk"
