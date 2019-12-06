# $NetBSD: Makefile,v 1.5 2019/12/06 20:19:02 markd Exp $

DISTNAME=	booktabs
PKGNAME=	tex-${DISTNAME}-1.618033
TEXLIVE_REV=	40846

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Publication quality tables in LaTeX
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
