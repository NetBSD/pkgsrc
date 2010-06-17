# $NetBSD: Makefile,v 1.7 2010/06/17 00:21:16 minskim Exp $

DISTNAME=	texlive-20091011-source
PKGNAME=	texlive-tetex-2009
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Scripts included in teTeX

CONFLICTS+=	teTeX-bin<=3.0nb22
DEPENDS+=	dialog>=1.0:../../misc/dialog
DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/tetex

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/tetex

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/updmap.cfg \
		${PKG_SYSCONFDIR}/web2c/updmap.cfg
FILES_SUBST+=	UPDMAP_SYS=${PREFIX}/bin/updmap-sys

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	fmtutil fmtutil-sys kpsetool kpsewhere \
			tcfmgr texconfig texconfig-dialog texconfig-sys \
			texlinks updmap updmap-sys
SUBST_SED.paths=	-e 's,@DIALOG@,${LOCALBASE}/bin/dialog,g' \
			-e 's,@FMTUTIL@,${PREFIX}/bin/fmtutil,g' \
			-e 's,@FMTUTIL_SYS@,${PREFIX}/bin/fmtutil-sys,g' \
			-e 's,@KPSEWHICH@,${LOCALBASE}/bin/kpsewhich,g' \
			-e 's,@LOCALBASE@,${LOCALBASE},g' \
			-e 's,@TEXCONFIG@,${PREFIX}/bin/texconfig,g' \
			-e 's,@TEXLINKS@,${PREFIX}/bin/texlinks,g' \
			-e 's,@UPDMAP@,${PREFIX}/bin/updmap,g' \
			-e 's,@UPDMAP_SYS@,${PREFIX}/bin/updmap-sys,g'

INSTALLATION_DIRS+=	share/texmf/web2c

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-install:
.for f in fmtutil.cnf updmap.cfg
	${INSTALL_DATA} ${FILESDIR}/${f} \
		${DESTDIR}${PREFIX}/share/texmf/web2c
.endfor

.include "../../mk/bsd.pkg.mk"
