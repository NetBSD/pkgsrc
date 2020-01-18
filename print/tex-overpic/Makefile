# $NetBSD: Makefile,v 1.8 2020/01/18 23:34:36 rillig Exp $

DISTNAME=	overpic
PKGNAME=	tex-${DISTNAME}-1.2
PKGREVISION=	1
TEXLIVE_REV=	48550

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/overpic
COMMENT=	Combine LaTeX commands over included graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-eepic-[0-9]*:../../graphics/tex-eepic

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
