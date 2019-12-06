# $NetBSD: Makefile,v 1.4 2019/12/06 20:22:55 markd Exp $

DISTNAME=	ntgclass
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	European versions of standard classes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
