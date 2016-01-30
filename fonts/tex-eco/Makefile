# $NetBSD: Makefile,v 1.2 2016/01/30 04:56:41 markd Exp $

DISTNAME=	eco
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Oldstyle numerals using EC fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
