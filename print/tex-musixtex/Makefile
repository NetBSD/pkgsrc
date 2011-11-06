# $NetBSD: Makefile,v 1.27 2011/11/06 08:43:32 minskim Exp $

DISTNAME=	musixtex
PKGNAME=	tex-${DISTNAME}-1.15
PKGREVISION=	1
TEXLIVE_REV=	22568

MAINTAINER=	dgriffi@cs.csubak.edu
COMMENT=	TeX macros for sophisticated music typesetting
LICENSE=	gnu-gpl-v2

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/musixtex
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'

REPLACE_TEXLUA=		bin/musixflx bin/musixtex
TEX_MIXEDMAP_FILES+=	musix.map
TEX_TEXMF_DIRS=		${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for f in musixflx musixtex
	${MV} ${WRKSRC}/texmf-dist/scripts/musixtex/${f}.lua ${WRKSRC}/bin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
