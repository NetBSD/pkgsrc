# $NetBSD: Makefile,v 1.5 2019/08/04 12:56:27 markd Exp $

DISTNAME=	hyphen-indic
PKGNAME=	tex-${DISTNAME}-2019.51186
TEXLIVE_REV=	51186

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Indic hyphenation patterns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-hyph-utf8-[0-9]*:../../print/tex-hyph-utf8

TEX_HYPHEN_DAT+=	assamese loadhyph-as.tex
TEX_HYPHEN_DEF+=	\\addlanguage{assamese}{loadhyph-as.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['assamese']={ \
			  loader='loadhyph-as.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-as.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	bengali loadhyph-bn.tex
TEX_HYPHEN_DEF+=	\\addlanguage{bengali}{loadhyph-bn.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['bengali']={ \
			  loader='loadhyph-bn.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-bn.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	gujarati loadhyph-gu.tex
TEX_HYPHEN_DEF+=	\\addlanguage{gujarati}{loadhyph-gu.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['gujarati']={ \
			  loader='loadhyph-gu.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-gu.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	hindi loadhyph-hi.tex
TEX_HYPHEN_DEF+=	\\addlanguage{hindi}{loadhyph-hi.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['hindi']={ \
			  loader='loadhyph-hi.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-hi.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	kannada loadhyph-kn.tex
TEX_HYPHEN_DEF+=	\\addlanguage{kannada}{loadhyph-kn.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['kannada']={ \
			  loader='loadhyph-kn.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-kn.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	malayalam loadhyph-ml.tex
TEX_HYPHEN_DEF+=	\\addlanguage{malayalam}{loadhyph-ml.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['malayalam']={ \
			  loader='loadhyph-ml.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-ml.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	marathi loadhyph-mr.tex
TEX_HYPHEN_DEF+=	\\addlanguage{marathi}{loadhyph-mr.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['marathi']={ \
			  loader='loadhyph-mr.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-mr.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	oriya loadhyph-or.tex
TEX_HYPHEN_DEF+=	\\addlanguage{oriya}{loadhyph-or.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['oriya']={ \
			  loader='loadhyph-or.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-or.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	panjabi loadhyph-pa.tex
TEX_HYPHEN_DEF+=	\\addlanguage{panjabi}{loadhyph-pa.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['panjabi']={ \
			  loader='loadhyph-pa.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-pa.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	pali loadhyph-pi.tex
TEX_HYPHEN_DEF+=	\\addlanguage{pali}{loadhyph-pi.tex}{}{1}{2}
TEX_HYPHEN_LUA+=	['pali']={ \
			  loader='loadhyph-pi.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=2, \
			  synonyms={}, \
			  patterns='hyph-pi.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	tamil loadhyph-ta.tex
TEX_HYPHEN_DEF+=	\\addlanguage{tamil}{loadhyph-ta.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['tamil']={ \
			  loader='loadhyph-ta.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-ta.pat.txt', \
			  hyphenation='', \
			},
TEX_HYPHEN_DAT+=	telugu loadhyph-te.tex
TEX_HYPHEN_DEF+=	\\addlanguage{telugu}{loadhyph-te.tex}{}{1}{1}
TEX_HYPHEN_LUA+=	['telugu']={ \
			  loader='loadhyph-te.tex', \
			  lefthyphenmin=1, \
			  righthyphenmin=1, \
			  synonyms={}, \
			  patterns='hyph-te.pat.txt', \
			  hyphenation='', \
			},

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
