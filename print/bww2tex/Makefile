# $NetBSD: Makefile,v 1.4 2004/01/20 12:24:28 agc Exp $
#

DISTNAME=	bww2tex-2.00
CATEGORIES=	print
MASTER_SITES=	http://www.stanford.edu/~wrinnes/bagpipe.tex/bww2tex/
DISTFILES=	bww2tex200.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://www.stanford.edu/~wrinnes/bagpipe.tex/bww2tex/
COMMENT=	Bagpipe Music Writer Gold to BagpipeTeX converter

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
MAKEFILE=	${WRKSRC}/makefile

do-install:
	${INSTALL_MAN} ${FILESDIR}/bww2tex.1 \
		${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bww2tex \
		${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
