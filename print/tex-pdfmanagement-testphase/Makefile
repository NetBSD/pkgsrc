# $NetBSD: Makefile,v 1.11 2025/05/10 22:47:01 markd Exp $

DISTNAME=	pdfmanagement-testphase
PKGNAME=	tex-${DISTNAME}-0.96q
TEXLIVE_REV=	74749

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdfmanagement-testphase
COMMENT=	LaTeX PDF management testphase bundle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-l3experimental-[0-9]*:../../devel/tex-l3experimental
# Cyclic dependency
#DEPENDS+=	tex-latex-lab-[0-9]*:../../print/tex-latex-lab
DEPENDS+=	tex-colorprofiles-[0-9]*:../../print/tex-colorprofiles

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
