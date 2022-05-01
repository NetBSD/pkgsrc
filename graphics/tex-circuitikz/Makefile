# $NetBSD: Makefile,v 1.10 2022/05/01 20:23:03 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.5.1
TEXLIVE_REV=	63145

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
