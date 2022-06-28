# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	texlive-scripts-extra
PKGNAME=	tex-${DISTNAME}-2020
PKGREVISION=	3
TEXLIVE_REV=	54744

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	More TeXLive scripts
LICENSE=	gnu-gpl-v2 AND public-domain

DEPENDS+=	dialog>=1.0:../../misc/dialog
DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts
DEPENDS+=	ps2eps>=1.68:../../graphics/ps2eps
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pslatex-[0-9]*:../../print/tex-pslatex
DEPENDS+=	tex-epstopdf-[0-9]*:../../graphics/tex-epstopdf
DEPENDS+=	tex-pst-pdf-[0-9]*:../../graphics/tex-pst-pdf

USE_TOOLS+=	perl:run sh:run

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/kpsetool bin/kpsewhere \
			bin/texconfig bin/texconfig-dialog bin/texconfig-sys \
			bin/texlinks \
			texmf-dist/texconfig/tcfmgr
SUBST_SED.paths+=	-e 's,@DIALOG@,${PREFIX}/bin/dialog,g'
SUBST_SED.paths+=	-e 's,@FMTUTIL@,${PREFIX}/bin/fmtutil,g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@MKTEXLSR@,${PREFIX}/bin/mktexlsr,g'
SUBST_SED.paths+=	-e 's,@TEXCONF_DIALOG@,${PREFIX}/bin/texconfig-dialog,g'
SUBST_SED.paths+=	-e 's,@TEXLINKS@,${PREFIX}/bin/texlnks,g'
SUBST_SED.paths+=	-e 's,@TEXCONFIG@,${PREFIX}/bin/texconfig,g'
SUBST_SED.paths+=	-e 's,@UPDMAP@,${PREFIX}/bin/updmap,g'
SUBST_SED.paths+=	-e 's,@EPSTOPDF@,${PREFIX}/bin/epstopdf,g'

REPLACE_PERL=	bin/e2pall
REPLACE_SH=	bin/allcm bin/allneeded bin/dvi2fax bin/dvired \
		bin/kpsetool bin/kpsewhere bin/ps2frag bin/pslatex \
		bin/texconfig bin/texconfig-dialog bin/texconfig-sys bin/texlinks \
		texmf-dist/texconfig/tcfmgr

#TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
.for script in texconfig-dialog.sh texconfig-sys.sh texconfig.sh texlinks.sh
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive-extra/${script} \
		${WRKSRC}/bin/${script:S/.sh//}
.endfor
.for script in allcm.sh allneeded.sh dvi2fax.sh dvired.sh e2pall.pl \
		kpsetool.sh kpsewhere.sh ps2frag.sh pslatex.sh
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive-extra/${script} \
		${WRKSRC}/bin/${script:S/.pl//:S/.sh//}
.endfor
	${CHMOD} +x ${WRKSRC}/texmf-dist/texconfig/tcfmgr

post-install:
	${LN} -sf allcm ${DESTDIR}${PREFIX}/bin/allec
	${LN} -sf kpsetool ${DESTDIR}${PREFIX}/bin/kpsepath
	${LN} -sf kpsetool ${DESTDIR}${PREFIX}/bin/kpsexpand

.include "../../mk/bsd.pkg.mk"
