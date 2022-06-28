# $NetBSD: Makefile,v 1.15 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	pkfix
PKGNAME=	tex-${DISTNAME}-1.7
PKGREVISION=	7
TEXLIVE_REV=	26032

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Script to replace pk fonts in PostScript with Type 1 fonts
LICENSE=	lppl-1.3c

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
SUBST_SED.paths=	-e 's,@DVIPS@,${LOCALBASE}/bin/dvips,g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${LOCALBASE}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@TEX@,${LOCALBASE}/bin/tex,g'

INSTALLATION_DIRS+=	bin

TEX_TEXMF_DIRS=	none

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/pkfix/pkfix.pl ${WRKSRC}/bin/pkfix
	${RM} -rf ${WRKSRC}/texmf-dist

.include "../../mk/bsd.pkg.mk"
