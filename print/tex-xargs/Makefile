# $NetBSD: Makefile,v 1.2 2016/01/26 10:26:52 markd Exp $

DISTNAME=	xargs
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Define commands with many optional arguments
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-xkeyval>=2.6a:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
