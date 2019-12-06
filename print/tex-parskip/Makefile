# $NetBSD: Makefile,v 1.5 2019/12/06 20:22:59 markd Exp $

DISTNAME=	parskip
PKGNAME=	tex-${DISTNAME}-2.0c
TEXLIVE_REV=	49730

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/parskip
COMMENT=	Layout with zero \parindent, non-zero \parskip
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-ltxmisc<2010.20350

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
