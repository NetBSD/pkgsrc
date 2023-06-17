# $NetBSD: Makefile,v 1.3 2023/06/17 11:32:00 markd Exp $

DISTNAME=	hitex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2023.66924
TEXLIVE_REV=	66924

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hitex
COMMENT=	Documentation for tex-hitex
LICENSE=	x11

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
