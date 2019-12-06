# $NetBSD: Makefile,v 1.5 2019/12/06 20:18:43 markd Exp $

DISTNAME=	a4wide
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20943

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Wide a4 layout for LaTeX
LICENSE=	lppl-1.0

CONFLICTS+=	tex-ltxmisc<2009
DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
