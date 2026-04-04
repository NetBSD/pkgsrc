# $NetBSD: Makefile,v 1.19 2026/04/04 05:42:36 markd Exp $

DISTNAME=	collection-langportuguese
PKGNAME=	texlive-${DISTNAME}-2026
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	73303

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Portuguese TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-portuges-[0-9]*:../../print/tex-babel-portuges
# beamer-tut-pt is documentation only
# cursolatex is documentation only
DEPENDS+=	tex-feupphdteses-[0-9]*:../../print/tex-feupphdteses
DEPENDS+=	tex-hyphen-portuguese-[0-9]*:../../print/tex-hyphen-portuguese
# latex-via-exemplos is documentation only
# latexcheat-ptbr is documentation only
# lshort-portuguese is documentation only
DEPENDS+=	tex-numberpt-[0-9]*:../../print/tex-numberpt
DEPENDS+=	tex-ordinalpt-[0-9]*:../../print/tex-ordinalpt
DEPENDS+=	tex-ptlatexcommands-[0-9]*:../../print/tex-ptlatexcommands
DEPENDS+=	tex-tabularray-abnt-[0-9]*:../../print/tex-tabularray-abnt
# xypic-tut-pt is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
