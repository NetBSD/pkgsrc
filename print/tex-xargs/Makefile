# $NetBSD: Makefile,v 1.3 2019/12/06 20:23:43 markd Exp $

DISTNAME=	xargs
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Define commands with many optional arguments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval>=2.6a:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
