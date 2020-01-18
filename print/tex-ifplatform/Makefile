# $NetBSD: Makefile,v 1.4 2020/01/18 23:34:17 rillig Exp $

DISTNAME=	ifplatform
PKGNAME=	tex-${DISTNAME}-0.4a
TEXLIVE_REV=	45533

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ifplatform
COMMENT=	Conditionals to test which platform is being used
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
