# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 21:38:12 minskim Exp $

DISTNAME=	pst-eps
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Create EPS files from PSTricks figures

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
