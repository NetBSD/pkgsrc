# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:10 markd Exp $

DISTNAME=	clrscode
PKGNAME=	tex-${DISTNAME}-1.7
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Typesets pseudocode as in Introduction to Algorithms
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
