# $NetBSD: Makefile,v 1.5 2011/11/06 08:43:31 minskim Exp $

DISTNAME=	context
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	21345

MAINTAINER=	minskim@NetBSD.org
COMMENT=	The ConTeXt macro package

CONFLICTS+=	teTeX-bin<=3.0nb44
DEPENDS+=	luatex>=0.65.0:../../print/luatex
DEPENDS+=	tex-lm>=2.004nb1:../../fonts/tex-lm
DEPENDS+=	tex-metapost>=1.211:../../graphics/tex-metapost
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-pdftex>=1.40.11:../../print/tex-pdftex
DEPENDS+=	web2c>=2010nb4:../../print/web2c
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"cont-en pdftex cont-usr.tex -8bit *cont-en.ini\\ncont-en xetex cont-usr.tex -8bit *cont-en.ini\\nmetafun mpost - metafun.mp\\n"
TEX_MAP_FILES+=		original-context-symbol.map
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf mpost ${DESTDIR}${PREFIX}/bin/metafun

.include "../../mk/bsd.pkg.mk"
