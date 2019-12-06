# $NetBSD: Makefile,v 1.8 2019/12/06 20:23:44 markd Exp $

DISTNAME=	xcolor
PKGNAME=	tex-${DISTNAME}-2.12
PKGREVISION=	2
TEXLIVE_REV=	41044

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Driver-independent color extensions for LaTeX and pdfLaTeX
LICENSE=	lppl-1.2

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
