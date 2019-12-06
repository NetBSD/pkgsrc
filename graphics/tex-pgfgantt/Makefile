# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:29 markd Exp $

DISTNAME=	pgfgantt
PKGNAME=	tex-${DISTNAME}-5.0
TEXLIVE_REV=	46280

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pgfgantt
COMMENT=	Draw Gantt charts with TikZ
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
