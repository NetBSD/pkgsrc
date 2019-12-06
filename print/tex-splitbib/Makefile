# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:19 markd Exp $

DISTNAME=	splitbib
PKGNAME=	tex-${DISTNAME}-1.17
TEXLIVE_REV=	15878

MAINTAINER=	cheusov@NetBSD.org
COMMENT=	Split and reorder your bibliography
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
