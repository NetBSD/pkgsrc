# $NetBSD: Makefile,v 1.1.1.1 2011/10/26 20:33:02 minskim Exp $

DISTNAME=	epstopdf
PKGNAME=	tex-${DISTNAME}-2.16
TEXLIVE_REV=	19287

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Convert EPS to 'encapsulated' PDF using GhostScript

CONFLICTS=	texlive-pdftools<2011

EVAL_PREFIX+=	KPSEWHICH_PREFIX=kpathsea
USE_TOOLS+=	gs:run perl:run

REPLACE_PERL=	bin/epstopdf

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/epstopdf
SUBST_SED.paths+=	-e 's,@GHOSTSCRIPT@,${TOOLS_PATH.gs},g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${KPSEWHICH_PREFIX}/bin/kpsewhich,g'

INSTALLATION_DIRS=	bin
TEX_TEXMF_DIRS=		# empty

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/epstopdf/epstopdf.pl \
		${WRKSRC}/bin/epstopdf

post-install:
	${LN} -sf epstopdf ${DESTDIR}${PREFIX}/bin/repstopdf

.include "../../mk/bsd.pkg.mk"
