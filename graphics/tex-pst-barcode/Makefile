# $NetBSD: Makefile,v 1.3 2015/06/14 11:26:43 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.13
TEXLIVE_REV=	37353

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Print barcodes using PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
