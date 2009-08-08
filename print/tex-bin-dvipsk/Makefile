# $NetBSD: Makefile,v 1.8 2009/08/08 11:08:18 minskim Exp $
# TeX Live Revision 12898

DISTNAME=	bin-dvipsk
PKGNAME=	tex-${DISTNAME}-2008.12898

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for dvipsk

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/pkfix

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

TEXLIVE_IGNORE_PATTERNS=	texmf/dvips/base

.include "../../print/texlive/module.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/pkfix/pkfix.pl ${WRKSRC}/bin/pkfix
	${RM} -rf ${WRKSRC}/texmf/scripts

.include "../../mk/bsd.pkg.mk"
