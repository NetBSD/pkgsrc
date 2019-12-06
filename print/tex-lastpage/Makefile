# $NetBSD: Makefile,v 1.5 2019/12/06 20:21:49 markd Exp $

DISTNAME=	lastpage
PKGNAME=	tex-${DISTNAME}-1.2m
TEXLIVE_REV=	36680

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Reference last page for Page N of M type footers
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
