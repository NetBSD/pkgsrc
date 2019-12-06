# $NetBSD: Makefile,v 1.8 2019/12/06 20:04:31 markd Exp $

DISTNAME=	pst-barcode
PKGNAME=	tex-${DISTNAME}-0.18
TEXLIVE_REV=	45096

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pst-barcode
COMMENT=	Print barcodes using PostScript
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
