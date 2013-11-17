# $NetBSD: Makefile,v 1.2 2013/11/17 16:51:49 minskim Exp $

DISTNAME=	texconfig
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	29764

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Configuration utility for TeX

CONFLICTS+=	texlive-tetex<=2011nb1
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea

USE_TOOLS+=	sh:run

EVAL_PREFIX+=	KPSEWHICH_PREFIX=kpathsea

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/texconfig texmf-dist/texconfig/tcfmgr
SUBST_SED.paths=	-e 's,@FMTUTIL@,${LOCALBASE}/bin/fmtutil,g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${KPSEWHICH_PREFIX}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@MKTEXLSR@,${KPSEWHICH_PREFIX}/bin/mktexlsr,g'
SUBST_SED.paths+=	-e 's,@TEXCONF_DIALOG@,${LOCALBASE}/bin/texconfig-dialog,g'
SUBST_SED.paths+=	-e 's,@TEXLINKS@,${LOCALBASE}/bin/texlnks,g'
SUBST_SED.paths+=	-e 's,@UPDMAP@,${LOCALBASE}/bin/updmap,g'

REPLACE_SH=	bin/texconfig texmf-dist/texconfig/tcfmgr

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/texconfig.sh \
		${WRKSRC}/bin/texconfig
	${RMDIR} -p ${WRKSRC}/texmf-dist/scripts/tetex 2>/dev/null || ${TRUE}
	${CHMOD} +x ${WRKSRC}/texmf-dist/texconfig/tcfmgr

.include "../../mk/bsd.pkg.mk"
