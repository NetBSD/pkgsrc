# $NetBSD: Makefile,v 1.2 2015/04/21 23:48:03 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.12
TEXLIVE_REV=	32004

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Print barcodes using PostScript

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
