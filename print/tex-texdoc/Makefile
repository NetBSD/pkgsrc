# $NetBSD: Makefile,v 1.1.1.1 2012/02/09 21:20:31 minskim Exp $

DISTNAME=	texdoc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	24354

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation access for TeX distributions
LICENSE=	gnu-gpl-v3

CONFLICTS+=	teTeX-bin<3.0nb50
DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

REPLACE_PERL=		bin/texdoctk
REPLACE_TEXLUA=		bin/texdoc
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/tetex/texdoctk.pl ${WRKSRC}/bin/texdoctk
	${RMDIR} ${WRKSRC}/texmf/scripts/tetex
	${MV} ${WRKSRC}/texmf/scripts/texdoc/texdoc.tlu ${WRKSRC}/bin/texdoc

.include "../../mk/bsd.pkg.mk"
