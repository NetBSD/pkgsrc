# $NetBSD: Makefile,v 1.11 2005/05/16 01:15:33 jlam Exp $

DISTNAME=	TeXfamily-1.2.1
PKGREVISION=	5
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.math.s.chiba-u.ac.jp/tex/texfam-1.2/ \
		ftp://ftp.math.s.chiba-u.ac.jp/tex/texfam-1.2.1/ \
		ftp://ftp.math.s.chiba-u.ac.jp/tex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/dvips/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/
DISTFILES=	texfam-1.2${EXTRACT_SUFX} \
		web2c-j1.9${EXTRACT_SUFX} \
		web2c-j1.9.1${EXTRACT_SUFX} \
		web2c-m0.8${EXTRACT_SUFX} \
		web2c-m0.8.1${EXTRACT_SUFX} \
		dvi2ps-3.2j${EXTRACT_SUFX} \
		jmakeindex${EXTRACT_SUFX} \
		ptex-src-${TEXFAMILY_PTEXVERSION}${EXTRACT_SUFX} \
		dvipsk-jpatch-p${TEXFAMILY_DVIPSVERSION}${EXTRACT_SUFX} \
		mendexk${TEXFAMILY_MENDEXVERSION}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PATCHFILES=	ptex-src-${TEXFAMILY_PTEXVERSION}.patch
PATCH_DIST_ARGS= -d ${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION}

MAINTAINER=	kei@NetBSD.org
COMMENT=	TeXfamily (pTeX, JTeX, MuLTeX) - executables

DEPENDS+=	TeXfamily-share>=1.2.1nb3:../../print/texfamily-share
DEPENDS+=	ja-vflib-lib-[0-9]*:../../print/ja-vflib-lib

DIST_SUBDIR=	TeXfamily
TETEX_DIR=	${PKGSRCDIR}/print/teTeX1-bin/${WRKDIR:T}/teTeX-1.0
WRKSRC=		${TETEX_DIR}
EXTRACT_ONLY=	# none

PKGSRC_USE_TOOLS+=	gtar

BUILD_TARGET=	all
INSTALL_TARGET=	install strip
USE_GNU_TOOLS+=	make
USE_X11=	yes
PLIST_SUBST+=	MV="${MV}"
CFLAGS+=	-Dunix
MAKEFLAGS+=	PREFIX=${PREFIX:Q}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--enable-local-texmf=texmf.local \
		--without-texinfo \
		--without-dialog \
		--disable-multiplatform \
		--enable-ipc \
		--with-epsfwin \
		--with-hp2627win \
		--with-mftalkwin \
		--with-x11 \
		--with-libwww-config=${LOCALBASE}/bin/libwww-config \
		--with-system-pnglib \
		--with-pnglib-libdir=${LOCALBASE}/lib \
		--with-pnglib-include=${LOCALBASE}/include \
		--with-system-zlib
.include "../../mk/bsd.prefs.mk"
.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=--enable-a4
.endif

.if ${OPSYS} != "SunOS"
CONFIGURE_ARGS+=--enable-auto-core \
		--with-zlib-libdir=/usr/lib \
		--with-zlib-include=/usr/include
.else
CONFIGURE_ARGS+= --with-zlib-libdir=${LOCALBASE}/lib \
		--with-zlib-include=${LOCALBASE}/include
.endif

CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

# Local versions
TEXFAMILY_PTEXVERSION=	3.0.1
TEXFAMILY_DVIPSVERSION=	1.5g
TEXFAMILY_MENDEXVERSION=2.5

pre-extract:
	if [ ! -r ${WRKSRC} ]; then \
		cd ../../print/teTeX1-bin && ${MAKE} patch; \
	elif [ ! -r ${WRKSRC}/texk/texfam.ac ]; then \
		cd ../../print/teTeX1-bin && ${MAKE} clean; ${MAKE} patch; \
	fi

post-extract:
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/texfam-1.2${EXTRACT_SUFX} \
		-C ${WRKSRC}/..
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/web2c-j1.9${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/web2c-j1.9.1${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/web2c-m0.8${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/web2c-m0.8.1${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/ptex-src-${TEXFAMILY_PTEXVERSION}${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk/web2c
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/dvi2ps-3.2j${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf \
		${DISTDIR}/${DIST_SUBDIR}/dvipsk-jpatch-p${TEXFAMILY_DVIPSVERSION}${EXTRACT_SUFX} \
		-C ${WRKDIR}
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/mendexk${TEXFAMILY_MENDEXVERSION}${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/jmakeindex${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${SED} -e "s|\$$TEXMF/ptex/plain/||" \
		${LOCALBASE}/share/texmf.local/ptex/plain/base/ptex.tex > \
		${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION}/ptex.tex
	${RM} -f ${WRKSRC}/texmf ${WRKSRC}/texmf.local
	${LN} -s ${LOCALBASE}/share/texmf ${WRKSRC}
	${LN} -s ${LOCALBASE}/share/texmf.local ${WRKSRC}

pre-patch:
	${PATCH} -d ${WRKSRC}/texk/dvipsk --quiet -E -p1 < \
		${WRKDIR}/dvipsk586.patch
#	${PATCH} -d ${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION} \
#		--quiet -E -p0 < ${DISTDIR}/${DIST_SUBDIR}/ptex-src-${TEXFAMILY_PTEXVERSION}.patch

post-patch:
	${MV} ${WRKSRC}/texk/kpathsea/texmf.in \
		${WRKSRC}/texk/kpathsea/texmf.in.orig
	${SED} -e 's,@TEXMFSITE@,${TEXMFSITE},' \
		${WRKSRC}/texk/kpathsea/texmf.in.orig > \
		${WRKSRC}/texk/kpathsea/texmf.in

post-configure:
	cd ${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION}; \
		./configure EUC ${LOCALBASE}/share/texmf.local

do-build:
	cd ${WRKSRC}/texk/web2c; ${GMAKE}
	cd ${WRKSRC}/texk/web2c-j; ${GMAKE}
	cd ${WRKSRC}/texk/web2c-m; ${GMAKE}
	cd ${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION}; ${GMAKE}
	cd ${WRKSRC}/texk/dvi2ps-3.2j; ${GMAKE} ${MAKEFLAGS} all newlib
	cd ${WRKSRC}/texk/dvipsk; ${GMAKE}
	cd ${WRKSRC}/texk/mendexk${TEXFAMILY_MENDEXVERSION}; ${GMAKE}
	cd ${WRKSRC}/texk/jmakeindex/src; ${MAKE} -f makefile.unx

do-install:
	cd ${WRKSRC}/texk/web2c-j; ${GMAKE} install
	cd ${WRKSRC}/texk/web2c-m; ${GMAKE} install
	cd ${WRKSRC}/texk/web2c/ptex-${TEXFAMILY_PTEXVERSION}; ${GMAKE} install
	cd ${WRKSRC}/texk/dvi2ps-3.2j; \
		${GMAKE} install install-lib install-MakePK install-lprdvi
	cd ${WRKSRC}/texk/dvi2ps-3.2j; ${GMAKE} install install-man
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/texmf.local/doc/dvi2ps
	${INSTALL_DATA} ${WRKSRC}/texk/dvi2ps-3.2j/doc/* \
		${LOCALBASE}/share/texmf.local/doc/dvi2ps
	cd ${WRKSRC}/texk/dvipsk; \
		${SETENV} texmflcl=${LOCALBASE}/share/texmf.local \
		${GMAKE} install
	${INSTALL_PROGRAM} ${WRKSRC}/texk/mendexk${TEXFAMILY_MENDEXVERSION}/mendex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/texk/jmakeindex/src/jmakeindex \
		${PREFIX}/bin

post-install:
	${LOCALBASE}/bin/mktexlsr ${LOCALBASE}/share/texmf.local

pre-clean:
	cd ../../print/teTeX1-bin && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
