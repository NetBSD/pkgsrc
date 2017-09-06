# $NetBSD: Makefile,v 1.2 2017/09/06 16:49:43 wiz Exp $

DISTNAME=	psfrag
PKGNAME=	tex-${DISTNAME}-3.04
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Replace strings in encapsulated PostScript figures

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
