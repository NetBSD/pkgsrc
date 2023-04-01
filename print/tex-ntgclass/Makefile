# $NetBSD: Makefile,v 1.7 2023/04/01 12:20:01 markd Exp $

DISTNAME=	ntgclass
PKGNAME=	tex-${DISTNAME}-2.1f
TEXLIVE_REV=	65522

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ntgclass
COMMENT=	European versions of standard classes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
