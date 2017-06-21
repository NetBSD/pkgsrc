# $NetBSD: Makefile,v 1.6 2017/06/21 11:45:58 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.16a
TEXLIVE_REV=	43996

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-barcode
COMMENT=	Print barcodes using PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
