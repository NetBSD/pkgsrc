# $NetBSD: Makefile,v 1.6 2017/06/21 13:25:33 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	44379

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
