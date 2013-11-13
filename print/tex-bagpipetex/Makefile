# $NetBSD: Makefile,v 1.15 2013/11/13 19:23:27 minskim Exp $
#

DISTNAME=	bagpipetex-3.01
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://www.stanford.edu/~wrinnes/bagpipe.tex/distribution/
DISTFILES=	bagpipe301.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://www.stanford.edu/~wrinnes/bagpipe.tex/
COMMENT=	MusixTeX macros to typeset bagpipe music

BUILD_DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-musixtex>=1.15:../../print/tex-musixtex

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	share/texmf-dist/doc/bagpipetex \
			share/texmf-dist/doc/bagpipetex/examples \
			share/texmf-dist/fonts/tfm/bagpipetex \
			share/texmf-dist/fonts/source/bagpipetex \
			share/texmf-dist/tex/latex/bagpipetex

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/bagdoc.pdf \
		${WRKSRC}/quickref.pdf \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/Green.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/GreenTwo.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Bonnets.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Washer.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/BlackDonald.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/*.mf \
		${DESTDIR}${PREFIX}/share/texmf-dist/fonts/source/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.tfm \
		${DESTDIR}${PREFIX}/share/texmf-dist/fonts/tfm/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/bagpipe.tex \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.ini \
		${DESTDIR}${PREFIX}/share/texmf-dist/tex/latex/bagpipetex

do-build:
	cd ${WRKDIR} && pdftex bagdoc
	cd ${WRKDIR} && musixtex quickref

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
