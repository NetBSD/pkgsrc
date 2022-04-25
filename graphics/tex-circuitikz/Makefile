# $NetBSD: Makefile,v 1.9 2022/04/25 10:38:11 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.5.0
TEXLIVE_REV=	63116

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
