# $NetBSD: Makefile,v 1.4 2022/04/08 23:27:33 markd Exp $

DISTNAME=	incgraph
PKGNAME=	tex-${DISTNAME}-1.2.0
TEXLIVE_REV=	60810

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/incgraph
COMMENT=	Sophisticated graphics inclusion in a PDF document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
