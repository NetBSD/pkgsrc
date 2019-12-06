# $NetBSD: Makefile,v 1.4 2019/12/06 20:21:35 markd Exp $

DISTNAME=	hyphenat
PKGNAME=	tex-${DISTNAME}-2.3c
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Disable/enable hypenation in LaTeX

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
