# $NetBSD: Makefile,v 1.2 2016/01/26 11:02:32 markd Exp $

DISTNAME=	supertabular
PKGNAME=	tex-${DISTNAME}-4.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Multi-page tables package
LICENSE=	lppl-1.3c

CONFLICTS=	teTeX-texmf<3.0nb33
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
