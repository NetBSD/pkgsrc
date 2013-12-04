# $NetBSD: Makefile,v 1.30 2013/12/04 02:42:07 minskim Exp $

DISTNAME=	musixtex
PKGNAME=	tex-${DISTNAME}-1.15pl29752
TEXLIVE_REV=	29752

MAINTAINER=	dgriffi@cs.csubak.edu
COMMENT=	TeX macros for sophisticated music typesetting
LICENSE=	gnu-gpl-v2

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-musixtex-fonts-[0-9]*:../../fonts/tex-musixtex-fonts
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

USE_TOOLS+=	gs:run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/musixtex
SUBST_SED.paths=	-e 's,@LOCALBASE@,${LOCALBASE},g'

REPLACE_TEXLUA=		bin/musixflx bin/musixtex

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for f in musixflx musixtex
	${MV} ${WRKSRC}/texmf-dist/scripts/musixtex/${f}.lua ${WRKSRC}/bin/${f}
.endfor
	cd ${WRKSRC}/texmf-dist && ${RMDIR} -p scripts/musixtex

.include "../../mk/bsd.pkg.mk"
