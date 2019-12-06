# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:07 markd Exp $

DISTNAME=	probsoln
PKGNAME=	tex-${DISTNAME}-3.05
TEXLIVE_REV=	44783

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/probsoln
COMMENT=	Generate problem sheets and their solution sheets
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
