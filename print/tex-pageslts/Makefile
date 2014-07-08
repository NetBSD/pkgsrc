# $NetBSD: Makefile,v 1.2 2014/07/08 15:22:08 joerg Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-1.2c
PKGREVISION=	1
TEXLIVE_USE_CTAN=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
