# $NetBSD: Makefile,v 1.3 2015/05/17 12:21:45 markd Exp $

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
# beamer-tut-pt is documentation only
# cursolatex is documentation only
# depend feupphdteses
DEPENDS+=	tex-hyphen-portuguese-[0-9]*:../../print/tex-hyphen-portuguese
# latexcheat-ptbr is documentation only
# lshort-portuguese is documentation only
# depend ordinalpt
# xypic-tut-pt is documentation only

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
