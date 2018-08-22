# $NetBSD: Makefile,v 1.13 2018/08/22 09:46:15 wiz Exp $

DISTNAME=	kotex-utils
PKGNAME=	tex-${DISTNAME}-2.1.0
PKGREVISION=	2
TEXLIVE_REV=	38727

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kotex-utils
COMMENT=	Utility scripts and support files for typesetting Korean
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kotex-utf-[0-9]*:../../print/tex-kotex-utf

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/jamo-normalize bin/komkindex bin/ttf2kotexfont

INSTALLATION_DIRS+=	bin

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/kotex-utils/jamo-normalize.pl \
		${WRKSRC}/bin/jamo-normalize
	${MV} ${WRKSRC}/texmf-dist/scripts/kotex-utils/komkindex.pl \
		${WRKSRC}/bin/komkindex
	${MV} ${WRKSRC}/texmf-dist/scripts/kotex-utils/ttf2kotexfont.pl \
		${WRKSRC}/bin/ttf2kotexfont
	${RM} -rf ${WRKSRC}/texmf-dist/scripts

.include "../../mk/bsd.pkg.mk"
