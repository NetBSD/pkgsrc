# $NetBSD: Makefile,v 1.8 2017/08/23 23:51:35 markd Exp $

DISTNAME=	pst-pdf
PKGNAME=	tex-${DISTNAME}-1.2d
TEXLIVE_REV=	44665

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-pdf
COMMENT=	Make PDF versions of graphics by processing between runs
LICENSE=	lppl-1.2

CONFLICTS=	texlive-pdftools<2011
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	tex-preview-[0-9]*:../../print/tex-preview
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks

USE_TOOLS+=	gs:run

USE_TOOLS+=	sed:run sh:run

REPLACE_SH=	bin/ps4pdf

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/ps4pdf
SUBST_SED.paths+=	-e 's,@DVIPS@,${LOCALBASE}/bin/dvips,g'
SUBST_SED.paths+=	-e 's,@LATEX@,${LOCALBASE}/bin/latex,g'
SUBST_SED.paths+=	-e 's,@PDFCROP@,${LOCALBASE}/bin/pdfcrop,g'
SUBST_SED.paths+=	-e 's,@PDFLATEX@,${LOCALBASE}/bin/pdflatex,g'
SUBST_SED.paths+=	-e 's,@PS2PDF@,${LOCALBASE}/bin/ps2pdf,g'
SUBST_SED.paths+=	-e 's,@SED@,${TOOLS_PATH.sed},g'

INSTALLATION_DIRS+=	bin

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts/pst-pdf/ps4pdf.bat*

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/pst-pdf/ps4pdf ${WRKSRC}/bin/

.include "../../mk/bsd.pkg.mk"
