# $NetBSD: Makefile,v 1.8 2016/01/30 04:05:50 markd Exp $

DISTNAME=	pdfcrop
PKGNAME=	tex-${DISTNAME}-1.37
PKGREVISION=	1
TEXLIVE_REV=	29348

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Crop PDF graphics
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-bin<3.0nb49

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
