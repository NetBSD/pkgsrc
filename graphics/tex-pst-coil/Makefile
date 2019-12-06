# $NetBSD: Makefile,v 1.4 2019/12/06 20:04:31 markd Exp $

DISTNAME=	pst-coil
PKGNAME=	tex-${DISTNAME}-1.07
TEXLIVE_REV=	37377

MAINTAINER=	minskim@NetBSD.org
COMMENT=	PSTricks package for coils, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
