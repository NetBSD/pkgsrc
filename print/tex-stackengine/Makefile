# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:19 markd Exp $

DISTNAME=	stackengine
PKGNAME=	tex-${DISTNAME}-4.01
TEXLIVE_REV=	43221

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/stackengine
COMMENT=	Highly customised stacking of objects, insets, baseline changes, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
