# $NetBSD: Makefile,v 1.4 2024/03/24 10:41:57 markd Exp $

DISTNAME=	hitex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024
TEXLIVE_REV=	70015

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hitex
COMMENT=	Documentation for tex-hitex
LICENSE=	x11

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
