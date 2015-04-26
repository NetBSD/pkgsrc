# $NetBSD: Makefile,v 1.3 2015/04/26 21:11:21 markd Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-1.2c
PKGREVISION=	1
TEXLIVE_REV=	32720

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
