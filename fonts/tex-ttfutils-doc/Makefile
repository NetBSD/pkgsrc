# $NetBSD: Makefile,v 1.3 2019/12/06 19:32:29 markd Exp $

DISTNAME=	ttfutils.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2013
TEXLIVE_REV=	31355

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ttfutils

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
