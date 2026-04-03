# $NetBSD: Makefile,v 1.17 2026/04/03 05:55:30 markd Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2026
TEXLIVE_REV=	78409

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Documentation for tex-dvipdfmx
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
