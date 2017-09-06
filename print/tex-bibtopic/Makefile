# $NetBSD: Makefile,v 1.3 2017/09/06 16:49:31 wiz Exp $

DISTNAME=	bibtopic
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Include multiple bibliographies in a document
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
