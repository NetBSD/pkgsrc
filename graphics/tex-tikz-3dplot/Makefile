# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:39 markd Exp $

DISTNAME=	tikz-3dplot
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	25087

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tikz-3dplot
COMMENT=	Coordinate transformation styles for 3d plotting in TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
