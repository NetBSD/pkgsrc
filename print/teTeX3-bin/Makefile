# $NetBSD: Makefile,v 1.39 2009/02/23 20:12:19 minskim Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	25
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	teTeX-texmf>=3.0nb3:../../print/teTeX3-texmf

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

INFO_FILES=	# PLIST

USE_TOOLS+=	bison lex

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--without-dvipsk --without-odvipsk
CONFIGURE_ARGS+=	--without-xdvik --without-oxdvik

MAKE_ENV+=		KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=		vartexfonts=${VARBASE:Q}/lib/texmf/fonts

BUILD_DEFS+=		VARBASE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
FILES_SUBST+=		PAPERSIZE=${LOWER_PAPERSIZE:Q}

OWN_DIRS+=	${VARBASE}/lib/texmf ${PREFIX}/share/texmf-local
.for d in pk source tfm
OWN_DIRS_PERMS+=	${VARBASE}/lib/texmf/fonts/${d} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
.endfor

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	texmf=${DESTDIR}${PREFIX}/share/texmf
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	share/texmf/fmtutil

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf

TEX_FORMAT_NAMES+=	tetex
TEX_MAP_FILES+=		antp.map
TEX_MAP_FILES+=		cork-antt.map
TEX_MAP_FILES+=		cs-antt.map
TEX_MAP_FILES+=		exp-antt.map
TEX_MAP_FILES+=		greek-antt.map
TEX_MAP_FILES+=		qx-antt.map
TEX_MAP_FILES+=		t2a-antt.map
TEX_MAP_FILES+=		t2b-antt.map
TEX_MAP_FILES+=		t2c-antt.map
TEX_MAP_FILES+=		t5-antt.map
TEX_MAP_FILES+=		texnansi-antt.map
TEX_MAP_FILES+=		wncy-antt.map
TEX_MAP_FILES+=		qbk.map
TEX_MAP_FILES+=		qcr.map
TEX_MAP_FILES+=		qhv.map
TEX_MAP_FILES+=		qpl.map
TEX_MAP_FILES+=		qtm.map
TEX_MAP_FILES+=		qzc.map
TEX_MAP_FILES+=		charter.map
TEX_MAP_FILES+=		cmcyr.map
TEX_MAP_FILES+=		contnav.map
TEX_MAP_FILES+=		cork-lm.map
TEX_MAP_FILES+=		qx-lm.map
TEX_MAP_FILES+=		texnansi-lm.map
TEX_MAP_FILES+=		ts1-lm.map
TEX_MAP_FILES+=		marvosym.map
TEX_MAP_FILES+=		mathpple.map
TEX_MAP_FILES+=		omega.map
TEX_MAP_FILES+=		pazo.map
TEX_MAP_FILES+=		pxfonts.map
TEX_MAP_FILES+=		txfonts.map
TEX_MAP_FILES+=		xypic.map
TEX_MAP_FILES+=		mt-belleek.map
TEX_MAP_FILES+=		urwvn.map
TEX_MAP_FILES+=		dstroke.map
TEX_MAP_FILES+=		fpls.map
TEX_MIXEDMAP_FILES+=	ttcmex.map
TEX_MIXEDMAP_FILES+=	bsr.map
TEX_MIXEDMAP_FILES+=	bsr-interpolated.map
TEX_MIXEDMAP_FILES+=	cs.map
TEX_MIXEDMAP_FILES+=	hoekwater.map
TEX_MIXEDMAP_FILES+=	pl.map
TEX_MIXEDMAP_FILES+=	ccpl.map
TEX_MIXEDMAP_FILES+=	eurosym.map
TEX_MIXEDMAP_FILES+=	vnr.map

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../print/teTeX3-bin/Makefile.common"
.include "../../print/texlive-tetex/format.mk"
.include "../../print/texlive-tetex/map.mk"

post-extract:
	${RM} -rf ${WRKSRC}/texk/kpathsea

.include "../../mk/bsd.pkg.mk"
