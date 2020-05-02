# $NetBSD: Makefile,v 1.9 2020/05/02 02:54:51 markd Exp $

DISTNAME=	xltxtra
PKGNAME=	tex-${DISTNAME}-0.7
PKGREVISION=	1
TEXLIVE_REV=	49555

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xltxtra
COMMENT=	Extras files for LaTeX users of XeTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-metalogo-[0-9]*:../../print/tex-metalogo
DEPENDS+=	tex-realscripts-[0-9]*:../../print/tex-realscripts
DEPENDS+=	tex-xetex-[0-9]*:../../print/tex-xetex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
