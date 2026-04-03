# $NetBSD: Makefile,v 1.2 2026/04/03 23:36:06 markd Exp $

DISTNAME=	ltx-talk
PKGNAME=	tex-${DISTNAME}-0.4.9
TEXLIVE_REV=	78575

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ltx-talk
COMMENT=	Class for typesetting presentations
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
