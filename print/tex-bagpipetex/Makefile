# $NetBSD: Makefile,v 1.1.1.1 2003/01/23 18:13:46 fredb Exp $
#

DISTNAME=	bagpipetex-3.01
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://www.stanford.edu/~wrinnes/bagpipe.tex/distribution/
DISTFILES=	bagpipe301.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://www.stanford.edu/~wrinnes/bagpipe.tex/
COMMENT=	MusixTeX macros to typeset bagpipe music

DEPENDS+=	tex-musixtex>=109:../tex-musixtex

NO_CONFIGURE=   yes
NO_BUILD=       yes
WRKSRC=         ${WRKDIR}

TEXMF_CNF=      ${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/bagpipetex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/bagpipetex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/bagpipetex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/bagdoc.tex \
		${WRKSRC}/quickref.tex \
		${PREFIX}/share/texmf/doc/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/Green.tex \
		${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/GreenTwo.tex \
		${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Bonnets.tex \
		${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Washer.tex \
		${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/BlackDonald.tex \
		${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/*.mf \
		${PREFIX}/share/texmf/fonts/source/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.tfm \
		${PREFIX}/share/texmf/fonts/tfm/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/bagpipe.tex \
		${PREFIX}/share/texmf/tex/latex/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.ini \
		${PREFIX}/share/texmf/tex/latex/bagpipetex
	${LOCALBASE}/bin/texconfig rehash

post-install:
	cd ${PREFIX}/share/texmf/doc/bagpipetex ; \
		latex bagdoc ; \
		dvips bagdoc.dvi -o bagdoc.ps ; \
		ps2pdf bagdoc.ps ; \
		musixtex quickref ; \
		musixflx quickref ; \
		musixtex quickref ; \
		dvips quickref.dvi -o quickref.ps ; \
		ps2pdf quickref.ps ; \
		${RM} -f *.log *.mx?

.include "../../mk/bsd.pkg.mk"
