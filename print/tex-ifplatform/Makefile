# $NetBSD: Makefile,v 1.6 2020/08/26 04:14:25 dholland Exp $

DISTNAME=	ifplatform
PKGNAME=	tex-${DISTNAME}-0.4a
PKGREVISION=	2
TEXLIVE_REV=	45533

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ifplatform
COMMENT=	Conditionals to test which platform is being used
LICENSE=	lppl-1.3c

DEPENDS+=	tex-catchfile-[0-9]*:../../print/tex-catchfile
DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
