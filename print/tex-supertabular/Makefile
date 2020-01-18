# $NetBSD: Makefile,v 1.6 2020/01/18 23:34:51 rillig Exp $

DISTNAME=	supertabular
PKGNAME=	tex-${DISTNAME}-4.1e
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/supertabular
COMMENT=	Multi-page tables package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
