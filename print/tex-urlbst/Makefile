# $NetBSD: Makefile,v 1.1 2017/01/20 23:22:49 markd Exp $

DISTNAME=	urlbst
PKGNAME=	tex-${DISTNAME}-0.7
TEXLIVE_REV=	29803

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/urlbst
COMMENT=	Web support for BibTeX
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/scripts/urlbst/urlbst

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
