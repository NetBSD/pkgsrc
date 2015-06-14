# $NetBSD: Makefile,v 1.3 2015/06/14 13:28:52 markd Exp $

DISTNAME=	collection-langcjk
PKGNAME=	texlive-${DISTNAME}-2015pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	37224

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Chinese/Japanese/Korean (base) TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
DEPENDS+=	tex-c90-[0-9]*:../../print/tex-c90
# cjk-gs-integrate
DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk
DEPENDS+=	tex-cjkpunct-[0-9]*:../../print/tex-cjkpunct
DEPENDS+=	tex-cjkutils-[0-9]*:../../print/tex-cjkutils
DEPENDS+=	tex-dnp-[0-9]*:../../print/tex-dnp
DEPENDS+=	tex-garuda-c90-[0-9]*:../../fonts/tex-garuda-c90
DEPENDS+=	tex-norasi-c90-[0-9]*:../../fonts/tex-norasi-c90
DEPENDS+=	tex-xcjk2uni-[0-9]*:../../print/tex-xcjk2uni
DEPENDS+=	tex-zxjafont-[0-9]*:../../print/tex-zxjafont

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
