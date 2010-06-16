# $NetBSD: Makefile,v 1.1.1.1 2010/06/16 23:57:26 minskim Exp $

DISTNAME=	metapost
PKGNAME=	tex-${DISTNAME}-1.211
TEXLIVE_REV=	17650

MAINTAINER=	minskim@NetBSD.org
COMMENT=	A development of MetaFont for creating graphics

CONFLICTS+=	teTeX-texmf<=3.0nb25
DEPENDS+=	tex-kpathsea>=2009.16044:../../print/tex-kpathsea
DEPENDS+=	web2c>=2009:../../print/web2c

INSTALLATION_DIRS+=	bin

TEX_FORMATS+=		"mpost mpost - mpost.mp\\nmfplain mpost - mfplain.ini\\n"
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-install:
	${LN} -sf mpost ${DESTDIR}${PREFIX}/bin/mfplain

.include "../../mk/bsd.pkg.mk"
