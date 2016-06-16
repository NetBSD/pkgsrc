# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:13 markd Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-1.2f
TEXLIVE_REV=	39164

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
