# $NetBSD: Makefile,v 1.4 2019/12/06 20:18:46 markd Exp $

DISTNAME=	advdate
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	20538

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX package to print a date relative to "today"
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
