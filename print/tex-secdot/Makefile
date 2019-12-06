# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:14 markd Exp $

DISTNAME=	secdot
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	20208

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Section numbers with trailing dots
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
