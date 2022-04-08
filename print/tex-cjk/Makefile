# $NetBSD: Makefile,v 1.7 2022/04/08 05:36:36 markd Exp $

DISTNAME=	cjk
PKGNAME=	tex-${DISTNAME}-4.8.5
TEXLIVE_REV=	60865

MAINTAINER=	rxg@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cjk
COMMENT=	CJK language support
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-arphic-[0-9]*:../../fonts/tex-arphic
DEPENDS+=	tex-cns-[0-9]*:../../fonts/tex-cns
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-garuda-c90-[0-9]*:../../fonts/tex-garuda-c90
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-norasi-c90-[0-9]*:../../fonts/tex-norasi-c90
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-uhc-[0-9]*:../../fonts/tex-uhc
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-wadalab-[0-9]*:../../fonts/tex-wadalab

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
