# $NetBSD: Makefile,v 1.1 2022/04/17 11:06:41 markd Exp $

DISTNAME=	hitex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2022
TEXLIVE_REV=	62529

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hitex
COMMENT=	Documentation for tex-hitex
LICENSE=	x11

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
