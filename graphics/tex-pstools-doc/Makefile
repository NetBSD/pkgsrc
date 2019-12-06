# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:33 markd Exp $

DISTNAME=	pstools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.68
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Documentation for tex-pstools
LICENSE=	lppl-1.3c

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/bbox.*
TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/ps2eps.*

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
