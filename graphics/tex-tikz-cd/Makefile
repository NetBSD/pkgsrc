# $NetBSD: Makefile,v 1.1 2016/04/23 22:32:02 markd Exp $

DISTNAME=	tikz-cd
PKGNAME=	tex-${DISTNAME}-0.9e
CATEGORIES=	graphics math print
TEXLIVE_REV=	35485

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/tex-archive/graphics/pgf/contrib/tikz-cd
COMMENT=	Create commutative diagrams with TikZ
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pgf-3.*:../../print/tex-pgf

USE_LANGUAGES=	# none

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
