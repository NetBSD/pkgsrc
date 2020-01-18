# $NetBSD: Makefile,v 1.7 2020/01/18 23:31:49 rillig Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	46940

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
