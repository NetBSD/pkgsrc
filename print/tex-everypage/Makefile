# $NetBSD: Makefile,v 1.6 2019/12/06 20:19:33 markd Exp $

DISTNAME=	everypage
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	15878

MAINTAINER=	reed@reedmedia.net
COMMENT=	LaTeX package for hooks to run on every page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
