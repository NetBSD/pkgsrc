# $NetBSD: Makefile,v 1.2 2026/03/26 08:07:40 markd Exp $

DISTNAME=	hyphen-albanian
PKGNAME=	tex-${DISTNAME}-2026
TEXLIVE_REV=	78069

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hyphenation patterns for Albanian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	albanian loadhyph-sq.tex
TEX_HYPHEN_DEF+=	\\addlanguage{albanian}{loadhyph-sq.tex}{}{2}{2}
TEX_HYPHEN_LUA+=	['albanian']={ \
			  loader='loadhyph-sq.tex', \
			  lefthyphenmin=2, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-sq.pat.txt', \
			  hyphenation = '', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
