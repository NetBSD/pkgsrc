# $NetBSD: Makefile,v 1.2 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	texlive-tetex-2008
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	Scripts included in teTeX

CONFLICTS+=	teTeX-bin<=3.0nb22
DEPENDS+=	dialog>=1.0:../../misc/dialog
DEPENDS+=	tex-bin-tetex-[0-9]*:../../print/tex-bin-tetex

EXTRACT_ELEMENTS=	${DISTNAME}/texk/tetex \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

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

FIND_PREFIX:=	DIALOG_PREFIX=dialog
.include "../../mk/find-prefix.mk"

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting a path to dialog.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	texconfig-dialog
SUBST_SED.paths=	-e 's,@DIALOG_PREFIX@,${DIALOG_PREFIX},g'

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

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
