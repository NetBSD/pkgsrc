# $NetBSD: Makefile,v 1.1 2015/05/06 10:41:43 markd Exp $

DISTNAME=	collection-langcjk
PKGNAME=	texlive-${DISTNAME}-2014pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	34022

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Chinese/Japanese/Korean (base) TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
# depend c90
DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk
# depend cjkpunct
DEPENDS+=	tex-cjkutils-[0-9]*:../../print/tex-cjkutils
# depend dnp
DEPENDS+=	tex-garuda-c90-[0-9]*:../../fonts/tex-garuda-c90
DEPENDS+=	tex-norasi-c90-[0-9]*:../../fonts/tex-norasi-c90
# depend xcjk2uni
# depend zxjafont

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
