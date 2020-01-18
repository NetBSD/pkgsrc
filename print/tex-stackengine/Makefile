# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:50 rillig Exp $

DISTNAME=	stackengine
PKGNAME=	tex-${DISTNAME}-4.01
TEXLIVE_REV=	43221

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/stackengine
COMMENT=	Highly customised stacking of objects, insets, baseline changes, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
