# $NetBSD: Makefile,v 1.6 2023/09/28 21:43:10 joerg Exp $

DISTNAME=	pageslts
PKGNAME=	tex-${DISTNAME}-1.2f
PKGREVISION=	1
TEXLIVE_REV=	39164

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide labels for the last page in each page numbering group
LICENSE=	lppl-1.3c

DEPENDS+=	tex-alphalph-[0-9]*:../../print/tex-alphalph
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-undolabl-[0-9]*:../../print/tex-undolabl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
