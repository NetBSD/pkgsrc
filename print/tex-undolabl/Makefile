# $NetBSD: Makefile,v 1.4 2023/04/02 11:42:10 markd Exp $

DISTNAME=	undolabl
PKGNAME=	tex-${DISTNAME}-1.0m
TEXLIVE_REV=	65846

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/undolabl
COMMENT=	Override existing labels
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
