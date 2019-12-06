# $NetBSD: Makefile,v 1.2 2019/12/06 20:19:23 markd Exp $

DISTNAME=	cyrillic-bin
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cyrillic bibtex and makeindex

USE_TOOLS+=	sh:run

REPLACE_SH=	bin/rubibtex bin/rumakeindex

TEX_TEXMF_DIRS=	# none

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/rubibtex.sh \
		${WRKSRC}/bin/rubibtex
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/rumakeindex.sh \
		${WRKSRC}/bin/rumakeindex
	${RM} -r ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
