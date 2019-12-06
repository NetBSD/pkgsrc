# $NetBSD: Makefile,v 1.2 2019/12/06 20:23:18 markd Exp $

DISTNAME=	soulpos
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	51479

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/soulpos
COMMENT=	Fancy means of underlining
LICENSE=	mit

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
