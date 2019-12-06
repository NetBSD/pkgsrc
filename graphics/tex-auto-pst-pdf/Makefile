# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:18 markd Exp $

DISTNAME=	auto-pst-pdf
PKGNAME=	tex-${DISTNAME}-0.6
TEXLIVE_REV=	23723

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper for pst-pdf (with some psfrag features)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-ifplatform-[0-9]*:../../print/tex-ifplatform
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
