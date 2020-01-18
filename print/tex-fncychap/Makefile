# $NetBSD: Makefile,v 1.3 2020/01/18 23:34:10 rillig Exp $

DISTNAME=	fncychap
PKGNAME=	tex-${DISTNAME}-1.34
TEXLIVE_REV=	20710

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/fncychap
COMMENT=	Seven predefined chapter heading styles
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
