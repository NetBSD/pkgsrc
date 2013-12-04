# $NetBSD: Makefile,v 1.1 2013/12/04 18:34:47 minskim Exp $

DISTNAME=	pstools
PKGNAME=	tex-${DISTNAME}-1.68
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Produce Encapsulated PostScript from PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	ps2eps>=1.68:../../graphics/ps2eps
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pslatex-[0-9]*:../../print/tex-pslatex

USE_TOOLS+=	sh:run

REPLACE_SH=	bin/ps2frag bin/pslatex

TEX_TEXMF_DIRS=	# none

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/ps2frag.sh \
		${WRKSRC}/bin/ps2frag
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/pslatex.sh \
		${WRKSRC}/bin/pslatex
	${RM} -r ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
