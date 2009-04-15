# $NetBSD: Makefile,v 1.1.1.1 2009/04/15 07:27:04 minskim Exp $
# TeX Live Revision 9013

DISTNAME=	hyphen-chinese
PKGNAME=	tex-${DISTNAME}-2008.9013

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation patterns for Chinese

CONFLICTS+=	teTeX-texmf<=3.0nb12
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	pinyin loadhyph-zh-latn.tex
TEX_HYPHEN_DEF+=	\addlanguage{pinyin}{loadhyph-zh-latn.tex}{}{1}{1}

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
