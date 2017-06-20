# $NetBSD: Makefile,v 1.2 2017/06/20 22:07:24 markd Exp $

DISTNAME=	circuitikz
PKGNAME=	tex-${DISTNAME}-0.8.3
TEXLIVE_REV=	44488

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/circuitikz
COMMENT=	Draw electrical networks with TikZ
LICENSE=	lppl-1.3c OR gnu-gpl-v1

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
