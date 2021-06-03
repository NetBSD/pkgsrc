# $NetBSD: Makefile,v 1.9 2021/06/03 08:00:34 markd Exp $

DISTNAME=	kotex-oblivoir
PKGNAME=	tex-${DISTNAME}-3.0.1
TEXLIVE_REV=	58436

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kotex-oblivoir
COMMENT=	LaTeX document class for typesetting Korean documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
