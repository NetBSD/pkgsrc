# $NetBSD: Makefile,v 1.4 2015/11/25 12:53:09 jperkin Exp $

DISTNAME=	texconfig
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34642

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Configuration utility for TeX

CONFLICTS+=	texlive-tetex<=2011nb1
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea

USE_TOOLS+=	sh:run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/texconfig texmf-dist/texconfig/tcfmgr
SUBST_SED.paths=	-e 's,@FMTUTIL@,${LOCALBASE}/bin/fmtutil,g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${LOCALBASE}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@MKTEXLSR@,${LOCALBASE}/bin/mktexlsr,g'
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
