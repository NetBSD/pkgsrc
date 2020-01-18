# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:03 rillig Exp $

DISTNAME=	endfloat
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	51003

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/endfloat
COMMENT=	Move floats to the end with markers where they belong
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
