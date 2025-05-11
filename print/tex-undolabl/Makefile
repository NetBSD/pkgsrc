# $NetBSD: Makefile,v 1.5 2025/05/11 00:06:35 markd Exp $

DISTNAME=	undolabl
PKGNAME=	tex-${DISTNAME}-1.0o
TEXLIVE_REV=	73633

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/undolabl
COMMENT=	Override existing labels
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
