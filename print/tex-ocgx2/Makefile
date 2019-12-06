# $NetBSD: Makefile,v 1.6 2019/12/06 20:22:56 markd Exp $

DISTNAME=	ocgx2
PKGNAME=	tex-${DISTNAME}-0.43
TEXLIVE_REV=	51552

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ocgx2
COMMENT=	Drop-in replacement for 'ocgx' and 'ocg-p'
LICENSE=	lppl-1.3c

DEPENDS+=	tex-media9-[0-9]*:../../print/tex-media9

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
