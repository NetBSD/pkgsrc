# $NetBSD: Makefile,v 1.8 2023/04/01 22:22:55 markd Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	64330

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
