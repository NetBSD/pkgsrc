# $NetBSD: Makefile,v 1.2 2021/06/06 23:04:55 markd Exp $

DISTNAME=	platex-tools
PKGNAME=	tex-${DISTNAME}-2021
TEXLIVE_REV=	59403

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
