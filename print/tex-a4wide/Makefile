# $NetBSD: Makefile,v 1.4 2016/01/30 03:26:05 markd Exp $

DISTNAME=	a4wide
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	20943

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Wide a4 layout for LaTeX
LICENSE=	lppl-1.0

CONFLICTS+=	tex-ltxmisc<2009
DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
