# $NetBSD: Makefile,v 1.2 2015/05/09 23:31:53 markd Exp $

DISTNAME=	collection-langportuguese
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	30962

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Portuguese TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-babel-portuges-[0-9]*:../../print/tex-babel-portuges
# depend beamer-tut-pt
# depend cursolatex
# depend feupphdteses
DEPENDS+=	tex-hyphen-portuguese-[0-9]*:../../print/tex-hyphen-portuguese
# depend latexcheat-ptbr
# lshort-portuguese is documentation only
# depend ordinalpt
# depend xypic-tut-pt

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
