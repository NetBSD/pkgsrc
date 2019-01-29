# $NetBSD: Makefile,v 1.3 2019/01/29 07:54:18 markd Exp $

DISTNAME=	pst-text
PKGNAME=	tex-${DISTNAME}-1.02
TEXLIVE_REV=	49542

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-text
COMMENT=	Text and character manipulation in PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
