# $NetBSD: Makefile,v 1.11 2011/11/06 08:43:28 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.24482
TEXLIVE_REV=	24482

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

CONFLICTS=	texlive-tetex<2011
DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra

USE_TOOLS+=	perl:run sh:run

FILES_SUBST+=	UPDMAP_SYS=${PREFIX}/bin/updmap-sys

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/updmap bin/updmap-sys
SUBST_SED.paths=	-e 's,@KPSEWHICH@,${LOCALBASE}/bin/kpsewhich,g' \
			-e 's,@UPDMAP@,${PREFIX}/bin/updmap,g'

REPLACE_PERL=	bin/updmap
REPLACE_SH=	bin/updmap-sys

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/web2c/updmap.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf/scripts/tetex/updmap-sys.sh \
		${WRKSRC}/bin/updmap-sys
	${MV} ${WRKSRC}/texmf/scripts/tetex/updmap.pl ${WRKSRC}/bin/updmap
	${RMDIR} -p ${WRKSRC}/texmf/scripts/tetex 2>/dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
