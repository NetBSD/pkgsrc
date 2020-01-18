# $NetBSD: Makefile,v 1.42 2020/01/18 23:34:32 rillig Exp $

DISTNAME=	musixtex
PKGNAME=	tex-${DISTNAME}-1.29
TEXLIVE_REV=	48353

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	https://ctan.org/pkg/musixtex
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
SUBST_VARS.paths=	LOCALBASE

REPLACE_TEXLUA=		bin/musixflx bin/musixtex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for f in musixflx musixtex
	${MV} ${WRKSRC}/texmf-dist/scripts/musixtex/${f}.lua ${WRKSRC}/bin/${f}
.endfor
	cd ${WRKSRC}/texmf-dist && ${RMDIR} -p scripts/musixtex

.include "../../mk/bsd.pkg.mk"
