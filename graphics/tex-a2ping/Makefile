# $NetBSD: Makefile,v 1.6 2013/12/03 20:15:47 minskim Exp $

DISTNAME=	a2ping
PKGNAME=	tex-${DISTNAME}-2.77p
PKGREVISION=	2
TEXLIVE_REV=	29725

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Advanced PS, PDF, EPS converter

CONFLICTS+=	teTeX-bin<=3.0nb34

USE_TOOLS+=	perl:run sh:run

REPLACE_SH=	bin/a2ping

SUBST_CLASSES+=		perl
SUBST_MESSAGE.perl=	Setting path to perl.
SUBST_STAGE.perl=	pre-configure
SUBST_FILES.perl=	bin/a2ping
SUBST_SED.perl=		-e 's,@PERL@,${PERL5},g'

TEX_TEXMF_DIRS=	none

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/a2ping/a2ping.pl ${WRKSRC}/bin/a2ping
	${RM} -r ${WRKSRC}/texmf-dist

pre-install:
	${RM} ${WRKSRC}/bin/*.orig

.include "../../mk/bsd.pkg.mk"
