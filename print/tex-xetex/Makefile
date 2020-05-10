# $NetBSD: Makefile,v 1.15 2020/05/10 04:32:07 markd Exp $

DISTNAME=	xetex
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	1
TEXLIVE_REV=	54276

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Unicode and OpenType-enabled TeX engine

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etex>=2.1:../../print/tex-etex
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latexconfig>=2010.20663:../../print/tex-latexconfig
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-plain>=3.141592653nb2:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-xetexconfig>=2010:../../print/tex-xetexconfig
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"xetex xetex language.def -etex xetex.ini\\nxelatex xetex language.dat -etex xelatex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf xetex ${DESTDIR}${PREFIX}/bin/xelatex

.include "../../mk/bsd.pkg.mk"
