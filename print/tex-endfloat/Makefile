# $NetBSD: Makefile,v 1.6 2019/12/06 20:19:29 markd Exp $

DISTNAME=	endfloat
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	51003

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/endfloat
COMMENT=	Move floats to the end with markers where they belong
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
