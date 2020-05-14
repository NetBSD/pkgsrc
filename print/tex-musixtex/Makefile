# $NetBSD: Makefile,v 1.44 2020/05/14 16:45:23 rillig Exp $

DISTNAME=	musixtex
PKGNAME=	tex-${DISTNAME}-1.30
TEXLIVE_REV=	54431

MAINTAINER=	dgriffi@cs.csubak.edu
HOMEPAGE=	https://ctan.org/pkg/musixtex
COMMENT=	TeX macros for sophisticated music typesetting
LICENSE=	gnu-gpl-v2

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-musixtex-fonts-[0-9]*:../../fonts/tex-musixtex-fonts
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

USE_TOOLS+=	gs:run

REPLACE_TEXLUA=		bin/musixflx bin/musixtex

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for f in musixflx musixtex
	${MV} ${WRKSRC}/texmf-dist/scripts/musixtex/${f}.lua ${WRKSRC}/bin/${f}
.endfor
	cd ${WRKSRC}/texmf-dist && ${RMDIR} -p scripts/musixtex

.include "../../mk/bsd.pkg.mk"
