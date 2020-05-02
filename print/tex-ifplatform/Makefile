# $NetBSD: Makefile,v 1.5 2020/05/02 02:48:24 markd Exp $

DISTNAME=	ifplatform
PKGNAME=	tex-${DISTNAME}-0.4a
PKGREVISION=	1
TEXLIVE_REV=	45533

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ifplatform
COMMENT=	Conditionals to test which platform is being used
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
