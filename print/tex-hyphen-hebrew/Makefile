# $NetBSD: Makefile,v 1.1 2025/05/07 11:52:15 markd Exp $

DISTNAME=	hyphen-hebrew
PKGNAME=	tex-${DISTNAME}-2025
TEXLIVE_REV=	74032

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hebrew hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	hebrew hyph-he.tex
TEX_HYPHEN_DEF+=	\\addlanguage{hebrew}{hyph-he.tex}{}{0}{0}
TEX_HYPHEN_LUA+=	['hebrew']={ \
			  loader='hyph-he.tex', \
			  lefthyphenmin=0, \
			  righthyphenmin=0, \
			  synonyms={}, \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
