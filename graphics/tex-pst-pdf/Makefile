# $NetBSD: Makefile,v 1.5 2016/01/30 04:05:53 markd Exp $

DISTNAME=	pst-pdf
PKGNAME=	tex-${DISTNAME}-1.1v
TEXLIVE_REV=	15878
PKGREVISION=	2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Make PDF versions of graphics by processing between runs
LICENSE=	lppl-1.3c

CONFLICTS=	texlive-pdftools<2011
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-environ-[0-9]*:../../print/tex-environ
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pdfcrop-[0-9]*:../../graphics/tex-pdfcrop
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def
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

TEXLIVE_IGNORE_PATTERNS=	scripts/pst-pdf/ps4pdf.bat*

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/scripts/pst-pdf/ps4pdf ${WRKSRC}/bin/

.include "../../mk/bsd.pkg.mk"
