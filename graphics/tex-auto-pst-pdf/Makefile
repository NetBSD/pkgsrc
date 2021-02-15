# $NetBSD: Makefile,v 1.4 2021/02/15 10:53:25 markd Exp $

DISTNAME=	auto-pst-pdf
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	56596

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/auto-pst-pdf
COMMENT=	Wrapper for pst-pdf (with some psfrag features)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
