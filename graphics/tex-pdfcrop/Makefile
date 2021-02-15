# $NetBSD: Makefile,v 1.15 2021/02/15 03:53:47 markd Exp $

DISTNAME=	pdfcrop
PKGNAME=	tex-${DISTNAME}-1.40
TEXLIVE_REV=	55435

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdfcrop
COMMENT=	Crop PDF graphics
LICENSE=	lppl-1.3c

USE_TOOLS+=	gs:run perl:run

REPLACE_PERL=	bin/pdfcrop

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/pdfcrop
SUBST_SED.paths+=	-e 's,@GHOSTSCRIPT@,${TOOLS_PATH.gs},g'

TEX_TEXMF_DIRS=	# empty

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/pdfcrop/pdfcrop.pl \
		${WRKSRC}/bin/pdfcrop

.include "../../mk/bsd.pkg.mk"
