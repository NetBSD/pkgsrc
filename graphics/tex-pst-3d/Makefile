# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:30 markd Exp $

DISTNAME=	pst-3d
PKGNAME=	tex-${DISTNAME}-1.10
TEXLIVE_REV=	17257

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for tilting and other pseudo-3D tricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
