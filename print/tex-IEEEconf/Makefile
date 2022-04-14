# $NetBSD: Makefile,v 1.3 2022/04/14 04:36:46 markd Exp $

DISTNAME=	ieeeconf
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	59665

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ieeeconf
COMMENT=	Macros for IEEE conference proceedings
LICENSE=	lppl-1.3c

DEPENDS+=	tex-fontinst-[0-9]*:../../fonts/tex-fontinst
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
