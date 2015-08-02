# $NetBSD: Makefile,v 1.4 2015/08/02 10:34:37 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.14
TEXLIVE_REV=	37586

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-barcode
COMMENT=	Print barcodes using PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
