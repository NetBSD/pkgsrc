# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:44 markd Exp $

DISTNAME=	collection-metapost
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	32455

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	MetaPost and Metafont packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend automata
# depend bbcard
# depend blockdraw_mp
# depend bpolynomial
# depend cmarrows
# depend drv
# depend dviincl
# depend emp
# depend epsincl
# depend expressg
# depend exteps
# depend featpost
# depend feynmf
# depend feynmp-auto
# depend garrigues
# depend gmp
# depend hatching
# depend latexmp
# depend metago
# depend metaobj
# depend metaplot
DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
# depend metauml
# depend mfpic
# depend mfpic4ode
# depend mp3d
# depend mpcolornames
# depend mpattern
# depend mpgraphics
# depend piechartmp
# depend repere
# depend roex
# depend slideshow
# depend splines
# depend suanpan
# depend textpath
# depend threeddice

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
