# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:10 markd Exp $

DISTNAME=	kotex-oblivoir
PKGNAME=	tex-${DISTNAME}-2.1.7
TEXLIVE_REV=	38679

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kotex-oblivoir
COMMENT=	LaTeX document class for typesetting Korean documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
