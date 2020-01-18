# $NetBSD: Makefile,v 1.4 2020/01/18 23:34:43 rillig Exp $

DISTNAME=	probsoln
PKGNAME=	tex-${DISTNAME}-3.05
TEXLIVE_REV=	44783

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/probsoln
COMMENT=	Generate problem sheets and their solution sheets
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
