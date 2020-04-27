# $NetBSD: Makefile,v 1.5 2020/04/27 02:08:13 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-1.1.1
TEXLIVE_REV=	54873

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	gnu-gpl-v2 AND lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
