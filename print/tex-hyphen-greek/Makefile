# $NetBSD: Makefile,v 1.2 2009/05/14 01:29:40 minskim Exp $
# TeX Live Revision 11160

DISTNAME=	hyphen-greek
PKGNAME=	tex-${DISTNAME}-2008.11160
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Greek

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	monogreek loadhyph-el-monoton.tex
TEX_HYPHEN_DAT+=	greek loadhyph-el-polyton.tex
TEX_HYPHEN_DAT+=	= polygreek
TEX_HYPHEN_DEF+=	\addlanguage{monogreek}{loadhyph-el-monoton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{greek}{loadhyph-el-polyton.tex}{}{1}{1}
TEX_HYPHEN_DEF+=	\addlanguage{polygreek}{loadhyph-el-polyton.tex}{}{1}{1}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
