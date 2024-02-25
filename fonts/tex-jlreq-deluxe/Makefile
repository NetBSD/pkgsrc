# $NetBSD: Makefile,v 1.4 2024/02/25 18:42:37 markd Exp $

DISTNAME=	jlreq-deluxe
PKGNAME=	tex-${DISTNAME}-0.5.0
TEXLIVE_REV=	69971

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq-deluxe
COMMENT=	Multi-weight Japanese font support for the jlreq class
LICENSE=	mit

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pxjodel-[0-9]*:../../fonts/tex-pxjodel

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
