# $NetBSD: Makefile,v 1.25 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	texlive-scripts
PKGNAME=	tex-${DISTNAME}-2022
PKGREVISION=	1
TEXLIVE_REV=	63029

MAINTAINER=	minskim@NetBSD.org
COMMENT=	TeX Live infrastructure programs
LICENSE=	gnu-gpl-v2 AND public-domain

DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	tex-kpathsea>=2012nb1:../../print/tex-kpathsea
DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra
# We want the manual pages
DEPENDS+=	tex-texlive-scripts-doc-[0-9]*:../../print/tex-texlive-scripts-doc

USE_TOOLS+=	gs:run perl:run sh:run

REPLACE_PERL=	bin/updmap bin/fmtutil texmf-dist/scripts/texlive/mktexlsr.pl
REPLACE_SH=	bin/fmtutil-sys bin/fmtutil-user bin/updmap-sys bin/updmap-user
REPLACE_TEXLUA=	bin/rungs

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/updmap.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

FILES_SUBST+=		UPDMAP_SYS=${PREFIX}/bin/updmap-sys

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	bin/rungs bin/mktexmf bin/mktexpk bin/mktextfm \
			bin/fmtutil bin/fmtutil-sys bin/updmap bin/updmap-sys
SUBST_SED.paths+=	-e 's,@GS@,${TOOLS_PATH.gs},g'
SUBST_SED.paths+=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@MKTEXMF@,${PREFIX}/bin/mktexmf,g'
SUBST_SED.paths+=	-e 's,@UPDMAP@,${PREFIX}/bin/updmap,g'
SUBST_SED.paths+=	-e 's,@FMTUTIL@,${PREFIX}/bin/fmtutil,g'

#TEX_MAP_FILES+=		mathpple.map

.include "../../print/texlive/package.mk"

post-extract:
	${MKDIR} ${WRKSRC}/bin
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/rungs.tlu \
		${WRKSRC}/bin/rungs
.for script in mktexmf mktexpk mktextfm
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/${script} \
		${WRKSRC}/bin/${script}
.endfor
.for script in fmtutil-sys.sh fmtutil-user.sh updmap-sys.sh updmap-user.sh
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/${script} \
		${WRKSRC}/bin/${script:S/.sh//}
.endfor
.for script in fmtutil.pl updmap.pl
	${MV} ${WRKSRC}/texmf-dist/scripts/texlive/${script} \
		${WRKSRC}/bin/${script:S/.pl//}
.endfor

post-install:
	${LN} -sf fmtutil ${DESTDIR}${PREFIX}/bin/mktexfmt
	${LN} -sf mktexlsr ${DESTDIR}${PREFIX}/bin/texhash

.include "../../mk/bsd.pkg.mk"
