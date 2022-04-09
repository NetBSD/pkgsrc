# $NetBSD: Makefile,v 1.4 2022/04/09 03:20:29 markd Exp $

DISTNAME=	stackengine
PKGNAME=	tex-${DISTNAME}-4.11
TEXLIVE_REV=	60019

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/stackengine
COMMENT=	Highly customised stacking of objects, insets, baseline changes, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
