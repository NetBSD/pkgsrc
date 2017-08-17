# $NetBSD: Makefile,v 1.2 2017/08/17 03:42:18 markd Exp $

DISTNAME=	probsoln
PKGNAME=	tex-${DISTNAME}-3.05
TEXLIVE_REV=	44783

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/probsoln
COMMENT=	Generate problem sheets and their solution sheets
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
