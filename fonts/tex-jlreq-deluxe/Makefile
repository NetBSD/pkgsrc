# $NetBSD: Makefile,v 1.5 2026/03/26 09:30:02 markd Exp $

DISTNAME=	jlreq-deluxe
PKGNAME=	tex-${DISTNAME}-0.6.0
TEXLIVE_REV=	78373

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq-deluxe
COMMENT=	Multi-weight Japanese font support for the jlreq class
LICENSE=	mit

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pxjodel-[0-9]*:../../fonts/tex-pxjodel

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
