# $NetBSD: Makefile,v 1.4 2019/12/06 20:19:00 markd Exp $

DISTNAME=	bibtopic
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Include multiple bibliographies in a document
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
