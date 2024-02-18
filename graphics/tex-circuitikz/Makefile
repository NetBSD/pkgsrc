# $NetBSD: Makefile,v 1.16 2024/02/18 09:53:08 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.6.7
TEXLIVE_REV=	69757

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
