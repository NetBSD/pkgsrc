# $NetBSD: Makefile,v 1.8 2021/05/30 08:04:41 markd Exp $

DISTNAME=	hyphen-afrikaans
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	58609

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Afrikaans hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base

TEX_HYPHEN_DAT+=	afrikaans loadhyph-af.tex
TEX_HYPHEN_DEF+=	\\addlanguage{afrikaans}{loadhyph-af.tex}{}{1}{2}
TEX_HYPHEN_LUA+=	['afrikaans']={ \
			  loader='loadhyph-af.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-af.pat.txt', \
			  hyphenation='hyph-af.hyp.txt', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
