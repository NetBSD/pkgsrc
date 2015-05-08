# $NetBSD: Makefile,v 1.1 2015/05/08 06:55:29 wiz Exp $

DISTNAME=	tex4ht
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	36701

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tex4ht
COMMENT=	Convert (La)TeX to HTML/XML
LICENSE=	lppl-1.3c

DEPENDS+=	tex4ht-[0-9]*:../../nih/tex4ht

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/scripts

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
