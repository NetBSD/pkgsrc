# $NetBSD: Makefile,v 1.3 2026/04/03 00:25:15 markd Exp $

DISTNAME=	bxcjkjatype
PKGNAME=	tex-${DISTNAME}-0.5a
TEXLIVE_REV=	78553

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxcjkjatype
COMMENT=	Typeset Japanese with pdfLaTeX and CJK
LICENSE=	mit

DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
