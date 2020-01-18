# $NetBSD: Makefile,v 1.6 2020/01/18 23:32:53 rillig Exp $

DISTNAME=	fp
PKGNAME=	tex-${DISTNAME}-2.1d
TEXLIVE_REV=	49719

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fp
COMMENT=	Fixed point arithmetic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
