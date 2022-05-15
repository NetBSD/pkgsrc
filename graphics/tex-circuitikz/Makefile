# $NetBSD: Makefile,v 1.11 2022/05/15 04:20:32 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.5.2
TEXLIVE_REV=	63269

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
