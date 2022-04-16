# $NetBSD: Makefile,v 1.14 2022/04/16 02:12:42 markd Exp $

DISTNAME=	collection-langcjk
PKGNAME=	texlive-${DISTNAME}-2022
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	61912

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Chinese/Japanese/Korean (base) TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-adobemapping-[0-9]*:../../fonts/tex-adobemapping
DEPENDS+=	tex-c90-[0-9]*:../../print/tex-c90
DEPENDS+=	tex-cjk-gs-integrate-[0-9]*:../../print/tex-cjk-gs-integrate
DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk
DEPENDS+=	tex-cjkpunct-[0-9]*:../../print/tex-cjkpunct
DEPENDS+=	tex-cjkutils-[0-9]*:../../print/tex-cjkutils
DEPENDS+=	tex-dnp-[0-9]*:../../print/tex-dnp
DEPENDS+=	tex-garuda-c90-[0-9]*:../../fonts/tex-garuda-c90
DEPENDS+=	tex-fixjfm-[0-9]*:../../print/tex-fixjfm
DEPENDS+=	tex-jfmutil-[0-9]*:../../print/tex-jfmutil
DEPENDS+=	tex-norasi-c90-[0-9]*:../../fonts/tex-norasi-c90
DEPENDS+=	tex-pxtatescale-[0-9]*:../../print/tex-pxtatescale
DEPENDS+=	tex-xcjk2uni-[0-9]*:../../print/tex-xcjk2uni
DEPENDS+=	tex-xecjk-[0-9]*:../../print/tex-xecjk
DEPENDS+=	tex-zitie-[0-9]*:../../print/tex-zitie
DEPENDS+=	tex-zxjafont-[0-9]*:../../print/tex-zxjafont

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
