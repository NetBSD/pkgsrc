# $NetBSD: Makefile,v 1.19 2019/12/06 20:21:47 markd Exp $

DISTNAME=	koma-script
PKGNAME=	tex-${DISTNAME}-3.26b
TEXLIVE_REV=	49929

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/koma-script
COMMENT=	Bundle of versatile classes and packages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
