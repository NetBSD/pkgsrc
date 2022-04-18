# $NetBSD: Makefile,v 1.1 2022/04/18 03:12:39 markd Exp $

DISTNAME=	footnotebackref
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	27034

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/footnotebackref
COMMENT=	Back-references from footnotes
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
