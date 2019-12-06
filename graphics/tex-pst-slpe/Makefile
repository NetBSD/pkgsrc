# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:35 markd Exp $

DISTNAME=	pst-slpe
PKGNAME=	tex-${DISTNAME}-1.31
TEXLIVE_REV=	24391

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Sophisticated colour gradients
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
