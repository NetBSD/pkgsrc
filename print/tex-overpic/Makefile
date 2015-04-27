# $NetBSD: Makefile,v 1.1 2015/04/27 12:35:35 markd Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-0.53
TEXLIVE_REV=	19712

MAINTAINER=	pkgsrc-users@NetBSD,org
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb44
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
