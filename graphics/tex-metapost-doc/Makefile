# $NetBSD: Makefile,v 1.9 2023/06/11 07:19:16 markd Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2023
TEXLIVE_REV=	66815

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/metapost
COMMENT=	Documentation for tex-metapost
LICENSE=	gnu-lgpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
