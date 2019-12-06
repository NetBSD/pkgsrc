# $NetBSD: Makefile,v 1.9 2019/12/06 20:23:31 markd Exp $

DISTNAME=	titlesec
PKGNAME=	tex-${DISTNAME}-2.11
TEXLIVE_REV=	51664

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/titlesec
COMMENT=	Select alternative section titles
LICENSE=	mit

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
