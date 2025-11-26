# $NetBSD: Makefile,v 1.13 2025/11/26 08:34:50 wiz Exp $

DISTNAME=	bww2tex-2.00
CATEGORIES=	print
#MASTER_SITES=	https://www.stanford.edu/~wrinnes/bagpipe.tex/bww2tex/
DISTFILES=	bww2tex200.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	https://github.com/DavidGriffith/bww2tex
COMMENT=	Bagpipe Music Writer Gold to BagpipeTeX converter

USE_TOOLS+=	bison

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
MAKE_FILE=	${WRKSRC}/makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_MAN} ${FILESDIR}/bww2tex.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bww2tex \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
