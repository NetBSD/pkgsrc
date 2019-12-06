# $NetBSD: Makefile,v 1.5 2019/12/06 19:29:55 markd Exp $

DISTNAME=	esint
PKGNAME=	tex-${DISTNAME}-1.2b
TEXLIVE_REV=	51679

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/esint
COMMENT=	Extended set of integrals for Computer Modern
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
