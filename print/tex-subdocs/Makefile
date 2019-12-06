# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:21 markd Exp $

DISTNAME=	subdocs
PKGNAME=	tex-${DISTNAME}-0.1
TEXLIVE_REV=	51480

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/subdocs
COMMENT=	Multifile documents
LICENSE=	mit

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
