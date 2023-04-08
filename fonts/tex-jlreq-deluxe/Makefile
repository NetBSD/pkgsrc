# $NetBSD: Makefile,v 1.3 2023/04/08 10:33:49 markd Exp $

DISTNAME=	jlreq-deluxe
PKGNAME=	tex-${DISTNAME}-0.4.1
TEXLIVE_REV=	66115

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jlreq-deluxe
COMMENT=	Multi-weight Japanese font support for the jlreq class
LICENSE=	mit

DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-pxjodel-[0-9]*:../../fonts/tex-pxjodel

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
