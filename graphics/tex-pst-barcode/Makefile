# $NetBSD: Makefile,v 1.7 2017/10/16 10:35:44 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.18
TEXLIVE_REV=	45096

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-barcode
COMMENT=	Print barcodes using PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
