# $NetBSD: Makefile,v 1.6 2009/04/27 15:18:47 minskim Exp $
# TeX Live Revision 12785

DISTNAME=	bin-dvipsk
PKGNAME=	tex-${DISTNAME}-2008.12785
PKGREVISION=	1

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

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pkfix ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
