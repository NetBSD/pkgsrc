# $NetBSD: Makefile,v 1.18 2025/05/11 04:02:21 markd Exp $

DISTNAME=	xetex
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	73850

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xetex
COMMENT=	Unicode and OpenType-enabled TeX engine
LICENSE=	x11

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-graphics-def-[0-9]*:../../print/tex-graphics-def
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	tex-tex-ini-files-[0-9]*:../../print/tex-tex-ini-files
DEPENDS+=	tex-unicode-data-[0-9]*:../../print/tex-unicode-data
DEPENDS+=	tex-xetexconfig-[0-9]*:../../print/tex-xetexconfig
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"xetex xetex language.def -etex xetex.ini\\nxelatex xetex language.dat -etex xelatex.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf xetex ${DESTDIR}${PREFIX}/bin/xelatex
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/texlive-extra/xelatex-unsafe.sh \
		${DESTDIR}${PREFIX}/bin/xelatex-unsafe
	${LN} -sf ${PREFIX}/share/texmf-dist/scripts/texlive-extra/xetex-unsafe.sh \
		${DESTDIR}${PREFIX}/bin/xetex-unsafe

.include "../../mk/bsd.pkg.mk"
