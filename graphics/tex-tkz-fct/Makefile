# $NetBSD: Makefile,v 1.3 2019/12/06 20:04:41 markd Exp $

DISTNAME=	tkz-fct
PKGNAME=	tex-${DISTNAME}-1.16c
TEXLIVE_REV=	22831

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tkz-fct
COMMENT=	Tools for drawing graphs of functions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-tkz-base-[0-9]*:../../graphics/tex-tkz-base

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
