# $NetBSD: Makefile,v 1.10 2024/03/20 11:07:08 markd Exp $

DISTNAME=	pdfmanagement-testphase
PKGNAME=	tex-${DISTNAME}-0.96f
TEXLIVE_REV=	70303

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
