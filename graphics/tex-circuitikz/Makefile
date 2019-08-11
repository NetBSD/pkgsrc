# $NetBSD: Makefile,v 1.3 2019/08/11 05:03:12 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-0.9.3
TEXLIVE_REV=	51634

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c OR gnu-gpl-v1

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
