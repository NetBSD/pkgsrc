# $NetBSD: Makefile,v 1.18 2013/11/17 17:15:43 minskim Exp $

DISTNAME=	tetex
PKGNAME=	tex-${DISTNAME}-3.0.32132
TEXLIVE_REV=	32132

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Supplementary files for updmap

CONFLICTS=	texlive-tetex<=2011nb1
DEPENDS+=	dialog>=1.0:../../misc/dialog
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	tex-kpathsea>=2012nb1:../../print/tex-kpathsea
DEPENDS+=	tex-texconfig>=2013:../../print/tex-texconfig
DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra

USE_TOOLS+=	perl:run sh:run

FILES_SUBST+=	UPDMAP_SYS=${PREFIX}/bin/updmap-sys

EVAL_PREFIX+=	DIALOG_PREFIX=dialog
EVAL_PREFIX+=	KPATHSEA_PREFIX=kpathsea
EVAL_PREFIX+=	TEXCONFIG_PREFIX=tex-texconfig

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/fmtutil bin/fmtutil-sys bin/kpsetool bin/kpsewhere \
			bin/texconfig-dialog bin/texconfig-sys bin/texlinks \
			bin/updmap bin/updmap-sys
SUBST_SED.paths+=	-e 's,@DIALOG@,${DIALOG_PREFIX}/bin/dialog,g'
SUBST_SED.paths+=	-e 's,@FMTUTIL@,${PREFIX}/bin/fmtutil,g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${KPATHSEA_PREFIX}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@TEXCONFIG@,${TEXCONFIG_PREFIX}/bin/texconfig,g'
SUBST_SED.paths+=	-e 's,@UPDMAP@,${PREFIX}/bin/updmap,g'

REPLACE_PERL=	bin/updmap
REPLACE_SH=	bin/allcm bin/allneeded bin/dvi2fax bin/dvired \
		bin/fmtutil-sys bin/fmtutil bin/kpsetool bin/kpsewhere \
		bin/texconfig-dialog bin/texconfig-sys bin/texlinks \
		bin/updmap-sys

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/updmap.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for script in fmtutil-sys.sh fmtutil.sh texconfig-dialog.sh \
		texconfig-sys.sh texlinks.sh
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/${script} \
		${WRKSRC}/bin/${script:S/.sh//}
.endfor
.for script in allcm.sh allneeded.sh dvi2fax.sh dvired.sh kpsetool.sh \
		kpsewhere.sh updmap-sys.sh updmap.pl
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/${script} \
		${WRKSRC}/bin/${script:S/.pl//:S/.sh//}
.endfor
	${RMDIR} -p ${WRKSRC}/texmf-dist/scripts/texlive 2>/dev/null || ${TRUE}

post-install:
	${LN} -sf allcm ${DESTDIR}${PREFIX}/bin/allec
	${LN} -sf kpsetool ${DESTDIR}${PREFIX}/bin/kpsepath
	${LN} -sf kpsetool ${DESTDIR}${PREFIX}/bin/kpsexpand
	${LN} -sf fmtutil ${DESTDIR}${PREFIX}/bin/mktexfmt

.include "../../mk/bsd.pkg.mk"
