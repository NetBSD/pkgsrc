# $NetBSD: Makefile,v 1.1.1.1 2011/10/19 23:41:53 minskim Exp $

DISTNAME=	cjk
PKGNAME=	tex-${DISTNAME}-4.8.2
TEXLIVE_REV=	15878

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
COMMENT=	CJK language support

DEPENDS+=	tex-arphic-[0-9]*:../../fonts/tex-arphic
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-garuda-c90-[0-9]*:../../fonts/tex-garuda-c90
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-norasi-c90-[0-9]*:../../fonts/tex-norasi-c90
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-thailatex-[0-9]*:../../print/tex-thailatex
DEPENDS+=	tex-uhc-[0-9]*:../../fonts/tex-uhc
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
