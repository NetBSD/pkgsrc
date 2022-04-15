# $NetBSD: Makefile,v 1.3 2022/04/15 04:17:15 markd Exp $

DISTNAME=	platex-tools
PKGNAME=	tex-${DISTNAME}-2021.61272
TEXLIVE_REV=	61272

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/platex-tools
COMMENT=	pLaTeX standard tools bundle
LICENSE=	modified-bsd

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-everysel-[0-9]*:../../print/tex-everysel
DEPENDS+=	tex-everyshi-[0-9]*:../../print/tex-everyshi
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
