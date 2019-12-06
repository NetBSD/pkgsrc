# $NetBSD: Makefile,v 1.4 2019/12/06 20:19:33 markd Exp $

DISTNAME=	euler
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	17261

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use AMS Euler fonts for math
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
