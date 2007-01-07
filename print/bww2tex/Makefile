# $NetBSD: Makefile,v 1.7 2007/01/07 09:14:09 rillig Exp $
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
MAKE_FILE=	${WRKSRC}/makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_MAN} ${FILESDIR}/bww2tex.1 \
		${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/bww2tex \
		${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
