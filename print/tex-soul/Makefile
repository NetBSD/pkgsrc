# $NetBSD: Makefile,v 1.4 2019/12/06 20:23:18 markd Exp $

DISTNAME=	soul
PKGNAME=	tex-${DISTNAME}-2.4
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Hyphenation for letterspacing, underlining, and more
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
