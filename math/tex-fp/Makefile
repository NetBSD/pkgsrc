# $NetBSD: Makefile,v 1.5 2019/12/06 19:07:32 markd Exp $

DISTNAME=	fp
PKGNAME=	tex-${DISTNAME}-2.1d
TEXLIVE_REV=	49719

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/fp
COMMENT=	Fixed point arithmetic
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
