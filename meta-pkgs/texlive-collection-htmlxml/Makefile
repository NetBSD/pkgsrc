# $NetBSD: Makefile,v 1.5 2016/06/16 04:03:13 markd Exp $

DISTNAME=	collection-htmlxml
PKGNAME=	texlive-${DISTNAME}-2016
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	35743

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	HTML/SGML/XML support TeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic
DEPENDS+=	texlive-collection-fontsrecommended-[0-9]*:../../meta-pkgs/texlive-collection-fontsrecommended
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex

DEPENDS+=	tex-classpack-[0-9]*:../../print/tex-classpack
DEPENDS+=	tex-jadetex-[0-9]*:../../print/tex-jadetex
DEPENDS+=	tex-passivetex-[0-9]*:../../print/tex-passivetex
DEPENDS+=	tex-tex4ht-[0-9]*:../../print/tex-tex4ht
DEPENDS+=	tex-xmltex-[0-9]*:../../textproc/tex-xmltex
DEPENDS+=	tex-xmltexconfig-[0-9]*:../../textproc/tex-xmltexconfig

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
