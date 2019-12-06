# $NetBSD: Makefile,v 1.8 2019/12/06 20:04:26 markd Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.803pl49482
TEXLIVE_REV=	49482

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-metapost
LICENSE=	gnu-lgpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
