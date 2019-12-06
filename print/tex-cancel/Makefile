# $NetBSD: Makefile,v 1.5 2019/12/06 20:19:04 markd Exp $

DISTNAME=	cancel
PKGNAME=	tex-${DISTNAME}-2.2
TEXLIVE_REV=	32508

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to place lines through maths formulae
LICENSE=	public-domain

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
