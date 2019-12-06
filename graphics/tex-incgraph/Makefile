# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:24 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
