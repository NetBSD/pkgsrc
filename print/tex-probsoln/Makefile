# $NetBSD: Makefile,v 1.1 2015/09/01 21:17:54 markd Exp $

DISTNAME=	probsoln
PKGNAME=	tex-${DISTNAME}-3.04
TEXLIVE_REV=	29371

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/probsoln
COMMENT=	Generate problem sheets and their solution sheets
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
