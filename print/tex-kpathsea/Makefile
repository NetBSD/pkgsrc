# $NetBSD: Makefile,v 1.12 2012/10/13 22:50:06 minskim Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2012
TEXLIVE_REV=	27341

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Translation tables for TeX
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
CONFLICTS+=	texlive-tetex<=2011nb1
DEPENDS+=	tex-tetex>=3.0.27774:../../print/tex-tetex
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/web2c/fmtutil.cnf \
				texmf/web2c/mktex.opt \
				texmf/web2c/mktex[a-z]* \
				texmf/web2c/texmf.cnf

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf fmtutil ${DESTDIR}${PREFIX}/bin/mktexfmt

.include "../../mk/bsd.pkg.mk"
