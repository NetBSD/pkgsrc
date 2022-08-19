# $NetBSD: Makefile,v 1.1 2022/08/19 19:59:06 wiz Exp $

DISTNAME=	dad.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.2
TEXLIVE_REV=	54191

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dad
COMMENT=	Documentation for tex-dad
LICENSE=	lppl-1.3c

REPLACE_PERL+=	doc/fonts/dad/dad-to-utf8.pl
REPLACE_PERL+=	doc/fonts/dad/make-dad-font.pl
REPLACE_PERL+=	doc/fonts/dad/utf8-to-dad.pl

USE_TOOLS+=	perl:run

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
