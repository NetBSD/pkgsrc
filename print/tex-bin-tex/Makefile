# $NetBSD: Makefile,v 1.1.1.1 2009/04/13 07:26:38 minskim Exp $
# TeX Live Revision 10592

DISTNAME=	bin-tex
PKGNAME=	tex-${DISTNAME}-2008.10592

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Plain TeX format

CONFLICTS+=	teTeX-bin<=3.0nb29
DEPENDS+=	tex-plain-[0-9]*:../../print/tex-plain
DEPENDS+=	web2c-[0-9]*:../../print/web2c

TEX_FORMAT_NAMES+=	tex
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
