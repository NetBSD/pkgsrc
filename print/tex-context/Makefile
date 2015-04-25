# $NetBSD: Makefile,v 1.8 2015/04/25 03:39:06 markd Exp $

DISTNAME=	context
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	35839

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The ConTeXt macro package

CONFLICTS+=	teTeX-bin<=3.0nb44
DEPENDS+=	tex-lm>=2.004nb1:../../fonts/tex-lm
DEPENDS+=	tex-manfnt>=2009:../../fonts/tex-manfnt
DEPENDS+=	tex-mflogo>=2009:../../fonts/tex-mflogo
DEPENDS+=	tex-luatex>=0.70.1pl30581nb1:../../print/tex-luatex
DEPENDS+=	tex-metapost>=1.211:../../graphics/tex-metapost
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex>=1.40.11:../../print/tex-pdftex
DEPENDS+=	web2c>=2010nb4:../../print/web2c
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

USE_TOOLS+=	sh:run

CHECK_INTERPRETER_SKIP=	share/texmf-dist/scripts/context/ruby/*.rb
REPLACE_SH=	bin/context bin/ctxtools bin/luatools
REPLACE_TEXLUA=	bin/mtxrun \
		texmf-dist/scripts/context/stubs/mswin/mtxrun.lua \
		texmf-dist/scripts/context/stubs/mswin/luatools.lua \
		texmf-dist/scripts/context/stubs/unix/mtxrun \
		texmf-dist/scripts/context/stubs/unix/luatools

TEX_FORMATS+=		"cont-en pdftex cont-usr.tex -8bit *cont-en.ini\\ncont-en xetex cont-usr.tex -8bit *cont-en.ini\\n"
TEX_MAP_FILES+=		original-context-symbol.map

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/context/lua/mtxrun.lua \
		${WRKSRC}/bin/mtxrun
.for f in context luatools texexec texmfstart
	${CP} ${WRKSRC}/texmf-dist/scripts/context/stubs/unix/${f} \
		${WRKSRC}/bin/
.endfor

.include "../../mk/bsd.pkg.mk"
