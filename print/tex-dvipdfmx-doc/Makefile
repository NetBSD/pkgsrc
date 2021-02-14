# $NetBSD: Makefile,v 1.14 2021/02/14 00:40:25 markd Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
TEXLIVE_REV=	56557

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Documentation for tex-dvipdfmx
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
