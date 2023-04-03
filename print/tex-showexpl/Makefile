# $NetBSD: Makefile,v 1.1 2023/04/03 11:40:04 markd Exp $

DISTNAME=	showexpl
PKGNAME=	tex-${DISTNAME}-0.3s
TEXLIVE_REV=	57414

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/showexpl
COMMENT=	Typesetting LaTeX source code
LICENSE=	lppl-1.2

DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-refcount-[0-9]*:../../print/tex-refcount
DEPENDS+=	tex-varwidth-[0-9]*:../../print/tex-varwidth

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
