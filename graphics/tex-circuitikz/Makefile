# $NetBSD: Makefile,v 1.7 2021/06/03 06:00:17 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.3.7
TEXLIVE_REV=	59421

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c AND gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
