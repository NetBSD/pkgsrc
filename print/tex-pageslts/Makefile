# $NetBSD: Makefile,v 1.1 2014/07/08 14:47:39 joerg Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-1.2c
TEXLIVE_USE_CTAN=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
