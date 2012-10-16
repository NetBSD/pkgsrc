# $NetBSD: Makefile,v 1.1 2012/10/16 21:58:39 minskim Exp $

DISTNAME=	ifplatform
PKGNAME=	tex-${DISTNAME}-0.3a
TEXLIVE_REV=	21156

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Conditionals to test which platform is being used
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifluatex-[0-9]*:../../print/tex-ifluatex
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
