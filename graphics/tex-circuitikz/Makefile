# $NetBSD: Makefile,v 1.12 2022/09/01 03:36:03 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.5.3
TEXLIVE_REV=	63788

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
