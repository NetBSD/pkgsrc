# $NetBSD: Makefile,v 1.4 2001/11/04 03:28:45 tv Exp $

DISTNAME=	bchunk-1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://hes.iki.fi/bchunk/

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://hes.iki.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

MAKE_FLAGS+=	CC="${CC}" LD="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${PREFIX}/man/man1/bchunk.1

.include "../../mk/bsd.pkg.mk"
