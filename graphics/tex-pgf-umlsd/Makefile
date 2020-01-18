# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:29 rillig Exp $

DISTNAME=	pgf-umlsd
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	33045

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pgf-umlsd
COMMENT=	Draw UML Sequence Diagrams
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
