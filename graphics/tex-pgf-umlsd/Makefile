# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:29 markd Exp $

DISTNAME=	pgf-umlsd
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	33045

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pgf-umlsd
COMMENT=	Draw UML Sequence Diagrams
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
