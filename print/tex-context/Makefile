# $NetBSD: Makefile,v 1.31 2025/05/12 07:55:17 markd Exp $

DISTNAME=	context
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74402

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/context
COMMENT=	The ConTeXt macro package

DEPENDS+=	tex-context-texlive-[0-9]*:../../print/tex-context-texlive
DEPENDS+=	tex-lm>=2.004nb1:../../fonts/tex-lm
DEPENDS+=	tex-lm-math-[0-9]*:../../fonts/tex-lm-math
DEPENDS+=	tex-manfnt-font>=2014:../../fonts/tex-manfnt-font
DEPENDS+=	tex-mflogo-font>=1.002:../../fonts/tex-mflogo-font
DEPENDS+=	tex-luajittex-[0-9]*:../../print/tex-luajittex
DEPENDS+=	tex-luatex>=0.70.1pl30581nb1:../../print/tex-luatex
DEPENDS+=	tex-metapost>=1.211:../../graphics/tex-metapost
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex>=1.40.11:../../print/tex-pdftex
DEPENDS+=	web2c>=2010nb4:../../print/web2c
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

TEX_MAP_FILES+=	original-context-symbol.map

USE_TOOLS+=	sh:run

REPLACE_TEXLUA=		bin/mtxrun

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/context/lua/mtxrun.lua \
		${WRKSRC}/bin/mtxrun

.include "../../mk/bsd.pkg.mk"
