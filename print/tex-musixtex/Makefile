# $NetBSD: Makefile,v 1.1.1.1 2003/01/23 18:11:05 fredb Exp $
#

DISTNAME=	musixtex-109
PKGNAME=	tex-${DISTNAME}
CATEGORIES=	print
#MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=macros/musixtex/taupin/}
DISTFILES=	musixtex-T109.tar.gz

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	http://icking-music-archive.sunsite.dk/
COMMENT=	TeX macros to typeset music

DEPENDS+=       teTeX-1.0*:../../print/teTeX

NO_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/musixtex-T109

TEXMF=		${LOCALBASE}/share/texmf
TEXMF_CNF=	${LOCALBASE}/share/texmf/web2c/texmf.cnf

do-build:
	@${ECHO} "======> Building musixtex.fmt"
	export TEXFONTS=${WRKSRC}/tfm ; \
		cd ${WRKSRC}/tex ; \
		initex '&tex musixtex.ins \dump'
	@${ECHO} "======> Building musixflx executable"
	cd ${WRKSRC}/systems/c-source; ${CC} -o musixflx musixflx.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/doc/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/tfm/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/fonts/source/musixtex
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf/tex/latex/musixtex
	${INSTALL_DATA} ${WRKSRC}/doc/* \
		${PREFIX}/share/texmf/doc/musixtex
	${INSTALL_DATA} ${WRKSRC}/tex/musixtex.fmt \
		${PREFIX}/share/texmf/web2c
	${INSTALL_DATA} ${WRKSRC}/mf/*.mf \
		${PREFIX}/share/texmf/fonts/source/musixtex
	${INSTALL_DATA} ${WRKSRC}/tfm/*.tfm \
		${PREFIX}/share/texmf/fonts/tfm/musixtex
	${INSTALL_DATA} ${WRKSRC}/tex/* \
		${PREFIX}/share/texmf/tex/latex/musixtex
	${INSTALL_PROGRAM} ${WRKSRC}/systems/c-source/musixflx \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/systems/c-source/musixflx.1 \
		${PREFIX}/man/man1
	cd ${PREFIX}/bin ; ${LN} -sf virtex musixtex
	${LOCALBASE}/bin/texconfig rehash

post-install:
	@${ECHO} "======> Building musixdoc.ps"
	cd ${PREFIX}/share/texmf/doc/musixtex ; \
		latex musixdoc ; \
		musixflx musixdoc ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		makeindex musixdoc.idx ; \
		latex  musixdoc ; \
		dvips musixdoc.dvi -o musixdoc.ps
	@${ECHO} "======> Converting musixdoc.ps into musixdoc.pdf"
	ps2pdf ${PREFIX}/share/texmf/doc/musixtex/musixdoc.ps \
		${PREFIX}/share/texmf/doc/musixtex/musixdoc.pdf

.include "../../mk/bsd.pkg.mk"
