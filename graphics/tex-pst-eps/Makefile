# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:32 markd Exp $

DISTNAME=	pst-eps
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Create EPS files from PSTricks figures
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
