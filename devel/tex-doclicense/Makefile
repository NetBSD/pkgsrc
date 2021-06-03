# $NetBSD: Makefile,v 1.9 2021/06/03 06:41:48 markd Exp $

DISTNAME=	doclicense
PKGNAME=	tex-${DISTNAME}-2.3.0
TEXLIVE_REV=	58350

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doclicense
COMMENT=	Support for putting documents under a license
LICENSE=	lppl-1.3c

DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-xifthen-[0-9]*:../../devel/tex-xifthen
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
