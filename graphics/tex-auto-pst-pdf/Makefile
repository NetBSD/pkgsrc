# $NetBSD: Makefile,v 1.3 2020/04/27 02:08:12 markd Exp $

DISTNAME=	auto-pst-pdf
PKGNAME=	tex-${DISTNAME}-0.6.52849
TEXLIVE_REV=	52849

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/auto-pst-pdf
COMMENT=	Wrapper for pst-pdf (with some psfrag features)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
