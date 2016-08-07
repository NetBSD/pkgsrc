# $NetBSD: Makefile,v 1.18 2016/08/07 09:09:38 markd Exp $

DISTNAME=	dvips.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016.41704
TEXLIVE_REV=	41704

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvips
COMMENT=	Documentation for tex-dvips
LICENSE=	gnu-gpl-v2

CONFLICTS+=	tex-bin-dvipsk-doc-[0-9]*

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/info texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
