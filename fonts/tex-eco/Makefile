# $NetBSD: Makefile,v 1.3 2019/12/06 19:29:53 markd Exp $

DISTNAME=	eco
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Oldstyle numerals using EC fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
