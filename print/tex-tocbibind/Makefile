# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:32 markd Exp $

DISTNAME=	tocbibind
PKGNAME=	tex-${DISTNAME}-1.5k
TEXLIVE_REV=	20085

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add bibliography/index/contents to Table of Contents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
