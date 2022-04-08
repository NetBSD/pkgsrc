# $NetBSD: Makefile,v 1.10 2022/04/08 21:09:47 markd Exp $

DISTNAME=	doclicense
PKGNAME=	tex-${DISTNAME}-3.0.0
TEXLIVE_REV=	59899

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doclicense
COMMENT=	Support for putting documents under a license
LICENSE=	cc0-1.0-universal AND lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
