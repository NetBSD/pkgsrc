# $NetBSD: Makefile,v 1.10 2016/06/16 04:06:03 markd Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	41149

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvipdfmx-def
COMMENT=	Documentation for tex-dvipdfmx
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
