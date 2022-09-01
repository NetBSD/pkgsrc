# $NetBSD: Makefile,v 1.27 2022/09/01 05:27:20 markd Exp $

DISTNAME=	textpos
PKGNAME=	tex-${DISTNAME}-1.10.1
TEXLIVE_REV=	63967

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/textpos
COMMENT=	Place boxes at arbitrary positions on the LaTeX page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
