# $NetBSD: Makefile,v 1.3 2010/04/03 14:22:09 jakllsch Exp $
# TeX Live Revision 17600

DISTNAME=	graphics
PKGNAME=	tex-${DISTNAME}-1.0o
DIST_SUBDIR=	${PKGNAME_NOREV}-17600
PKGREVISION=	1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Standard LaTeX graphics

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-pdftex-def-[0-9]*:../../print/tex-pdftex-def

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
