# $NetBSD: Makefile,v 1.6 2020/01/18 23:34:36 rillig Exp $

DISTNAME=	parskip
PKGNAME=	tex-${DISTNAME}-2.0c
TEXLIVE_REV=	49730

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/parskip
COMMENT=	Layout with zero \parindent, non-zero \parskip
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2010.20350

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
