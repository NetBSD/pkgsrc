# $NetBSD: Makefile,v 1.13 2020/01/18 23:34:02 rillig Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016.41623
TEXLIVE_REV=	41623

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/dvipdfmx
COMMENT=	Documentation for tex-dvipdfmx
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
