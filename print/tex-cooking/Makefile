# $NetBSD: Makefile,v 1.6 2019/12/06 20:19:19 markd Exp $

DISTNAME=	cooking
PKGNAME=	tex-${DISTNAME}-0.9b
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Typeset recipes
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
