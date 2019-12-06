# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:39 markd Exp $

DISTNAME=	tikz-cd
PKGNAME=	tex-${DISTNAME}-0.9f
CATEGORIES=	graphics math print
TEXLIVE_REV=	49201

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/tex-archive/graphics/pgf/contrib/tikz-cd
COMMENT=	Create commutative diagrams with TikZ
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-pgf-3.*:../../print/tex-pgf

USE_LANGUAGES=	# none

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
