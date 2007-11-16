# $NetBSD: Makefile,v 1.10 2007/11/16 12:03:42 dillo Exp $

DISTNAME=	bchunk-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://he.fi/bchunk/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://he.fi/bchunk/
COMMENT=	".bin/.cue" CD image converter

MAKE_FLAGS+=	CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bchunk ${PREFIX}/bin/bchunk
	${INSTALL_MAN} ${WRKSRC}/bchunk.1 ${PREFIX}/${PKGMANDIR}/man1/bchunk.1

.include "../../mk/bsd.pkg.mk"
