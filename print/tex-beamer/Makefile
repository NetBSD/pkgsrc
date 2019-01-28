# $NetBSD: Makefile,v 1.11 2019/01/28 09:14:06 markd Exp $

DISTNAME=	beamer
PKGNAME=	tex-${DISTNAME}-3.55
TEXLIVE_REV=	49306

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/beamer
COMMENT=	LaTeX class for producing presentations and slides
LICENSE=	lppl-1.3c OR gnu-gpl-v2

DEPENDS+=	tex-amscls-[0-9]*:../../print/tex-amscls
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-translator-[0-9]*:../../print/tex-translator
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
