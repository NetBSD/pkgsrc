# $NetBSD: Makefile,v 1.15 2022/04/17 10:18:56 markd Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2021
TEXLIVE_REV=	61101

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Documentation for tex-dvipdfmx
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
