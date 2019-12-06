# $NetBSD: Makefile,v 1.9 2019/12/06 20:19:33 markd Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.603
TEXLIVE_REV=	46084

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
