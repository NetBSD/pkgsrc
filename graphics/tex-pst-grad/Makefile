# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:32 markd Exp $

DISTNAME=	pst-grad
PKGNAME=	tex-${DISTNAME}-1.06
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Filling with colour gradients, using PStricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
