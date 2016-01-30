# $NetBSD: Makefile,v 1.2 2016/01/30 04:05:54 markd Exp $

DISTNAME=	pst-text
PKGNAME=	tex-${DISTNAME}-1.00
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Text and character manipulation in PSTricks
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
