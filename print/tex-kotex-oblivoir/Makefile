# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:19 rillig Exp $

DISTNAME=	kotex-oblivoir
PKGNAME=	tex-${DISTNAME}-2.1.8
TEXLIVE_REV=	43130

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/kotex-oblivoir
COMMENT=	LaTeX document class for typesetting Korean documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
