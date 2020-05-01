# $NetBSD: Makefile,v 1.3 2020/05/01 00:15:12 markd Exp $

DISTNAME=	cyrillic-bin
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	53559

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cyrillic bibtex and makeindex

USE_TOOLS+=	sh:run

REPLACE_SH=	bin/rubibtex bin/rumakeindex

TEX_TEXMF_DIRS=	# none

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive-extra/rubibtex.sh \
		${WRKSRC}/bin/rubibtex
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive-extra/rumakeindex.sh \
		${WRKSRC}/bin/rumakeindex
	${RM} -r ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
