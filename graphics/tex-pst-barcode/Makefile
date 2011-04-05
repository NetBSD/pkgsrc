# $NetBSD: Makefile,v 1.1.1.1 2011/04/05 19:37:53 minskim Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.08
TEXLIVE_REV=	21716

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Print barcodes using PostScript

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
