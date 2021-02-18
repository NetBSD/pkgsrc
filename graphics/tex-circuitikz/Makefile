# $NetBSD: Makefile,v 1.6 2021/02/18 19:42:07 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.3.0
TEXLIVE_REV=	57469

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
