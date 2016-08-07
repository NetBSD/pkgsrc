# $NetBSD: Makefile,v 1.5 2016/08/07 09:09:41 markd Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2016.41726
TEXLIVE_REV=	41726

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../print/tex4ht

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
