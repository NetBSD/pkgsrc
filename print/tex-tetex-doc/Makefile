# $NetBSD: Makefile,v 1.11 2012/07/22 20:24:42 minskim Exp $

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0.26894
TEXLIVE_REV=	26894

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42
CONFLICTS+=	texlive-tetex<2011

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS+=	texmf/doc/man/man1/a* texmf/doc/man/man1/d* \
				texmf/doc/man/man1/f* texmf/doc/man/man1/t* \
				texmf/doc/man/man5/f*

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
