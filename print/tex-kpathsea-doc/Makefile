# $NetBSD: Makefile,v 1.1.1.1 2010/02/14 22:14:47 minskim Exp $
# TeX Live Revision 16044

DISTNAME=	kpathsea.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16044

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-kpathsea

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/info/[kw]* \
				texmf/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
