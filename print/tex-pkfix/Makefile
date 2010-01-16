# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 03:48:32 minskim Exp $
# TeX Live Revision 15878

DISTNAME=	pkfix
PKGNAME=	tex-${DISTNAME}-1.5

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Script to replace pk fonts in PostScript with Type 1 fonts

CONFLICTS+=	tex-bin-dvipsk<=2008.12898
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	web2c-[0-9]*:../../print/web2c

USE_TOOLS+=	perl:run
REPLACE_PERL=	bin/pkfix

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/pkfix
SUBST_SED.paths=	-e 's,@DVIPS@,${LOCALBASE}/bin/dvips,g' \
			-e 's,@KPSEWHICH@,${LOCALBASE}/bin/kpsewhich,g' \
			-e 's,@TEX@,${LOCALBASE}/bin/tex,g'

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS=	none

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/pkfix/pkfix.pl ${WRKSRC}/bin/pkfix
	${RM} -rf ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
