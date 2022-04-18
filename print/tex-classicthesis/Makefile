# $NetBSD: Makefile,v 1.1 2022/04/18 03:45:00 markd Exp $

DISTNAME=	classicthesis
PKGNAME=	tex-${DISTNAME}-4.6
TEXLIVE_REV=	48041

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/classicthesis
COMMENT=	"Classically styled" thesis package
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-eulervm-[0-9]*:../../fonts/tex-eulervm
DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-mparhack-[0-9]*:../../print/tex-mparhack
DEPENDS+=	tex-prelim2e-[0-9]*:../../print/tex-prelim2e
DEPENDS+=	tex-textcase-[0-9]*:../../print/tex-textcase
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
