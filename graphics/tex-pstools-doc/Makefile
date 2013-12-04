# $NetBSD: Makefile,v 1.1 2013/12/04 18:35:15 minskim Exp $

DISTNAME=	pstools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.68
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-pstools
LICENSE=	lppl-1.3c

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/bbox.*
TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/ps2eps.*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
