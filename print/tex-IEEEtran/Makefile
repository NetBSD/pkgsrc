# $NetBSD: Makefile,v 1.14 2009/07/07 23:24:14 minskim Exp $
# TeX Live Revision 10804

DISTNAME=	IEEEtran
PKGNAME=	tex-${DISTNAME}-1.7a
PKGREVISION=	2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.michaelshell.org/tex/ieeetran/
COMMENT=	LaTeX class for IEEE journals and conferences

DEPENDS+=	tex-bin-latex-[0-9]*:../../print/tex-bin-latex
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
