# $NetBSD: Makefile,v 1.1 2022/04/18 03:42:00 markd Exp $

DISTNAME=	autonum
PKGNAME=	tex-${DISTNAME}-0.3.11
TEXLIVE_REV=	36084

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/autonum
COMMENT=	Automatic equation references
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-etextools-[0-9]*:../../print/tex-etextools
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-textpos-[0-9]*:../../print/tex-textpos

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
