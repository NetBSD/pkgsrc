# $NetBSD: Makefile,v 1.2 2024/02/03 03:03:13 markd Exp $

DISTNAME=	bxcjkjatype
PKGNAME=	tex-${DISTNAME}-0.5
TEXLIVE_REV=	67705

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxcjkjatype
COMMENT=	Typeset Japanese with pdfLaTeX and CJK
LICENSE=	mit

DEPENDS+=	tex-cjk-[0-9]*:../../print/tex-cjk
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
