# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:43 markd Exp $

DISTNAME=	selinput
PKGNAME=	tex-${DISTNAME}-1.6
TEXLIVE_REV=	53098

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/selinput
COMMENT=	Semi-automatic detection of input encoding
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
