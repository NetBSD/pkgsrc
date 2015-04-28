# $NetBSD: Makefile,v 1.2 2015/04/28 17:13:59 nros Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-0.53
TEXLIVE_REV=	19712

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb44
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
