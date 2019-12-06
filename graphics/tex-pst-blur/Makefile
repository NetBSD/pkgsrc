# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:31 markd Exp $

DISTNAME=	pst-blur
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for "blurred" shadows
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
