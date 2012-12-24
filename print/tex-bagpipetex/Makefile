# $NetBSD: Makefile,v 1.14 2012/12/24 05:17:51 dholland Exp $
#

DISTNAME=	bagpipetex-3.01
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	http://www.stanford.edu/~wrinnes/bagpipe.tex/distribution/
DISTFILES=	bagpipe301.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://www.stanford.edu/~wrinnes/bagpipe.tex/
COMMENT=	MusixTeX macros to typeset bagpipe music

BUILD_DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-musixtex>=1.15:../../print/tex-musixtex

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	share/texmf/doc/bagpipetex \
			share/texmf/doc/bagpipetex/examples \
			share/texmf/fonts/tfm/bagpipetex \
			share/texmf/fonts/source/bagpipetex \
			share/texmf/tex/latex/bagpipetex

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/bagdoc.dvi \
		${WRKSRC}/bagdoc.ps \
		${WRKSRC}/bagdoc.tex \
		${WRKSRC}/quickref.dvi \
		${WRKSRC}/quickref.ps \
		${WRKSRC}/quickref.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/Green.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/GreenTwo.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Bonnets.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/Washer.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/BlackDonald.tex \
		${DESTDIR}${PREFIX}/share/texmf/doc/bagpipetex/examples
	${INSTALL_DATA} ${WRKSRC}/*.mf \
		${DESTDIR}${PREFIX}/share/texmf/fonts/source/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.tfm \
		${DESTDIR}${PREFIX}/share/texmf/fonts/tfm/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/bagpipe.tex \
		${DESTDIR}${PREFIX}/share/texmf/tex/latex/bagpipetex
	${INSTALL_DATA} ${WRKSRC}/*.ini \
		${DESTDIR}${PREFIX}/share/texmf/tex/latex/bagpipetex

do-build:
	cd ${WRKDIR} && tex bagdoc
	cd ${WRKDIR} && dvips bagdoc.dvi -o bagdoc.ps
	cd ${WRKDIR} && musixtex quickref
	cd ${WRKDIR} && musixflx quickref
	cd ${WRKDIR} && musixtex quickref
	cd ${WRKDIR} && dvips quickref.dvi -o quickref.ps

.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
