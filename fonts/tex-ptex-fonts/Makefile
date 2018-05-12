# $NetBSD: Makefile,v 1.5 2018/05/12 01:53:37 markd Exp $

DISTNAME=	ptex-fonts
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	46940

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ptex-fonts
COMMENT=	Fonts for use with pTeX
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex-fontmaps-[0-9]*:../../fonts/tex-ptex-fontmaps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
