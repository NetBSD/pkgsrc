# $NetBSD: Makefile,v 1.1 2017/01/20 21:09:07 markd Exp $

DISTNAME=	incgraph
PKGNAME=	tex-${DISTNAME}-1.12
TEXLIVE_REV=	36500

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/incgraph
COMMENT=	Sophisticated graphics inclusion in a PDF document
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
