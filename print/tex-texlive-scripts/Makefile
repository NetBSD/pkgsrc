# $NetBSD: Makefile,v 1.11 2013/11/17 17:05:10 minskim Exp $

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	32115

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live infrastructure programs
LICENSE=	gnu-gpl-v2 AND public-domain

CONFLICTS+=	tex-bin-texlive-[0-9]*

USE_TOOLS+=	gs:run

REPLACE_TEXLUA=		bin/rungs \
			texmf-dist/scripts/texlive/lua/texlive/getopt.tlu \
			texmf-dist/scripts/texlive/lua/texlive/tlpdb.tlu \
			texmf-dist/scripts/texlive/test-tlpdb.tlu \
			texmf-dist/scripts/texlive/texconf.tlu

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/rungs
SUBST_SED.paths+=	-e 's,@GS@,${TOOLS_PATH.gs},g'

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/rungs.tlu \
		${WRKSRC}/bin/rungs

.include "../../mk/bsd.pkg.mk"
