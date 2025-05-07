# $NetBSD: Makefile,v 1.1 2025/05/07 11:54:54 markd Exp $

DISTNAME=	hyphen-vietnamese
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74032

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Vietnamese hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	vietnamese hyph-vi.tex
TEX_HYPHEN_DEF+=	\\addlanguage{vietnamese}{hyph-vi.tex}{}{0}{0}
TEX_HYPHEN_LUA+=	['vietnamese']={ \
			  loader='hyph-vi.tex', \
			  lefthyphenmin=0, \
			  righthyphenmin=0, \
			  synonyms={}, \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
