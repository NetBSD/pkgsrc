# $NetBSD: Makefile,v 1.9 2011/11/06 08:43:28 minskim Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	texlive-tetex-2011
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Scripts included in teTeX

CONFLICTS+=	teTeX-bin<=3.0nb22
DEPENDS+=	dialog>=1.0:../../misc/dialog
DEPENDS+=	kpathsea-[0-9]*:../../print/kpathsea
DEPENDS+=	tex-tetex>=3.0.24482:../../print/tex-tetex

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/tetex

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tetex

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf
FILES_SUBST+=	UPDMAP_SYS=${PREFIX}/bin/updmap-sys

EVAL_PREFIX+=	DIALOG_PREFIX=dialog
EVAL_PREFIX+=	KPSEWHICH_PREFIX=kpathsea
EVAL_PREFIX+=	UPDMAP_PREFIX=tex-tetex

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	fmtutil fmtutil-sys kpsetool kpsewhere \
			tcfmgr texconfig texconfig-dialog texconfig-sys \
			texlinks
SUBST_SED.paths=	-e 's,@DIALOG@,${DIALOG_PREFIX}/bin/dialog,g' \
			-e 's,@FMTUTIL@,${PREFIX}/bin/fmtutil,g' \
			-e 's,@FMTUTIL_SYS@,${PREFIX}/bin/fmtutil-sys,g' \
			-e 's,@KPSEWHICH@,${KPSEWHICH_PREFIX}/bin/kpsewhich,g' \
			-e 's,@LOCALBASE@,${LOCALBASE},g' \
			-e 's,@TEXCONFIG@,${PREFIX}/bin/texconfig,g' \
			-e 's,@TEXLINKS@,${PREFIX}/bin/texlinks,g' \
			-e 's,@UPDMAP@,${UPDMAP_PREFIX}/bin/updmap,g' \
			-e 's,@UPDMAP_SYS@,${UPDMAP_PREFIX}/bin/updmap-sys,g'

INSTALLATION_DIRS+=	share/texmf/web2c

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-install:
.for f in fmtutil.cnf
	${INSTALL_DATA} ${FILESDIR}/${f} \
		${DESTDIR}${PREFIX}/share/texmf/web2c
.endfor

.include "../../mk/bsd.pkg.mk"
