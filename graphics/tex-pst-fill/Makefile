# $NetBSD: Makefile,v 1.4 2022/04/10 06:15:33 markd Exp $

DISTNAME=	pst-fill
PKGNAME=	tex-${DISTNAME}-1.02
TEXLIVE_REV=	60671

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pst-fill
COMMENT=	Fill or tile areas with PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
