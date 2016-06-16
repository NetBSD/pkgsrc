# $NetBSD: Makefile,v 1.4 2016/06/16 04:06:16 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40208

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
