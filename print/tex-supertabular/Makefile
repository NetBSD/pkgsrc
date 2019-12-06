# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:22 markd Exp $

DISTNAME=	supertabular
PKGNAME=	tex-${DISTNAME}-4.1e
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/supertabular
COMMENT=	Multi-page tables package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
