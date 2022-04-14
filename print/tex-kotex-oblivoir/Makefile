# $NetBSD: Makefile,v 1.10 2022/04/14 01:58:21 markd Exp $

DISTNAME=	kotex-oblivoir
PKGNAME=	tex-${DISTNAME}-3.1.5
TEXLIVE_REV=	63005

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kotex-oblivoir
COMMENT=	LaTeX document class for typesetting Korean documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
