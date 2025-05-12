# $NetBSD: Makefile,v 1.1 2025/05/12 08:39:24 markd Exp $

DISTNAME=	multitoc
PKGNAME=	tex-${DISTNAME}-2.02
TEXLIVE_REV=	71520

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/multitoc
COMMENT=	Set table of contents in multiple columns
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
