# $NetBSD: Makefile,v 1.7 2001/12/15 20:25:36 agc Exp $

DISTNAME=	TeXfamily-1.2.1nb1
CATEGORIES=	japanese
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
		ptex-src-2.1.10${EXTRACT_SUFX} \
		dvipsk-jpatch-p1.5e${EXTRACT_SUFX} \
		mendexk2.4f${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/tetex/
PATCHFILES=	ptex2.1.10-11.patch
PATCH_DIST_ARGS= -d ${WRKSRC}/texk/web2c/ptex-src-2.1.10

MAINTAINER=	kei@netbsd.org
COMMENT=	TeXfamily (pTeX, JTeX, MuLTeX) - executables

DEPENDS+=	TeXfamily-share>=1.2.1nb1:../../japanese/texfamily-share
DEPENDS+=	ja-vflib-lib-[0-9]*:../../japanese/vflib-lib

DIST_SUBDIR=	TeXfamily
TETEX_DIR=	${_PKGSRCDIR}/print/teTeX-bin/${WRKDIR:T}/teTeX-1.0
WRKSRC=		${TETEX_DIR}
EXTRACT_ONLY=	# none

ALL_TARGET=	all
INSTALL_TARGET=	install strip
USE_GMAKE=	yes
USE_X11=	yes
PLIST_SUBST+=	MV="${MV}"
CFLAGS+=	-Dunix
MAKEFLAGS+=	PREFIX=${PREFIX}
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

pre-extract:
	if [ ! -e ${WRKSRC} ]; then \
		cd ../../print/teTeX-bin && ${MAKE} patch; \
	elif [ ! -e ${WRKSRC}/texk/texfam.ac ]; then \
		cd ../../print/teTeX-bin && ${MAKE} clean; ${MAKE} patch; \
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
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/ptex-src-2.1.10${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk/web2c
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/dvi2ps-3.2j${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf \
		${DISTDIR}/${DIST_SUBDIR}/dvipsk-jpatch-p1.5e${EXTRACT_SUFX} \
		-C ${WRKDIR}
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/mendexk2.4f${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${GTAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/jmakeindex${EXTRACT_SUFX} \
		-C ${WRKSRC}/texk
	${SED} -e "s|\$TEXMF/ptex/plain/||" \
		${LOCALBASE}/share/texmf.local/ptex/plain/base/ptex.tex > \
		${WRKSRC}/texk/web2c/ptex-src-2.1.10/ptex.tex
	${RM} -f ${WRKSRC}/texmf ${WRKSRC}/texmf.local
	${LN} -s ${LOCALBASE}/share/texmf ${WRKSRC}
	${LN} -s ${LOCALBASE}/share/texmf.local ${WRKSRC}

pre-patch:
	${PATCH} -d ${WRKSRC}/texk/dvipsk --quiet -E -p1 < \
		${WRKDIR}/dvipsk586.patch

post-patch:
	${MV} ${WRKSRC}/texk/kpathsea/texmf.in \
		${WRKSRC}/texk/kpathsea/texmf.in.orig
	${SED} -e 's,@TEXMFSITE@,${TEXMFSITE},' \
		${WRKSRC}/texk/kpathsea/texmf.in.orig > \
		${WRKSRC}/texk/kpathsea/texmf.in 

post-configure:
	(cd ${WRKSRC}/texk/web2c/ptex-src-2.1.10; \
		./configure EUC ${LOCALBASE}/share/texmf.local)

do-build:
	(cd ${WRKSRC}/texk/web2c; ${GMAKE})
	(cd ${WRKSRC}/texk/web2c-j; ${GMAKE})
	(cd ${WRKSRC}/texk/web2c-m; ${GMAKE})
	(cd ${WRKSRC}/texk/web2c/ptex-src-2.1.10; ${GMAKE})
	(cd ${WRKSRC}/texk/dvi2ps-3.2j; ${GMAKE} ${MAKEFLAGS} all newlib)
	(cd ${WRKSRC}/texk/dvipsk; ${GMAKE})
	(cd ${WRKSRC}/texk/mendexk2.4f; ${GMAKE})
	(cd ${WRKSRC}/texk/jmakeindex/src; ${MAKE} -f makefile.unx)

do-install:
	(cd ${WRKSRC}/texk/web2c-j; ${GMAKE} install)
	(cd ${WRKSRC}/texk/web2c-m; ${GMAKE} install)
	(cd ${WRKSRC}/texk/web2c/ptex-src-2.1.10; ${GMAKE} install)
	(cd ${WRKSRC}/texk/dvi2ps-3.2j; \
		${GMAKE} install install-lib install-MakePK install-lprdvi)
	(cd ${WRKSRC}/texk/dvi2ps-3.2j; ${GMAKE} install install-man)
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/texmf.local/doc/dvi2ps
	${INSTALL_DATA} ${WRKSRC}/texk/dvi2ps-3.2j/doc/* \
		${LOCALBASE}/share/texmf.local/doc/dvi2ps
	(cd ${WRKSRC}/texk/dvipsk; \
		${SETENV} texmflcl=${LOCALBASE}/share/texmf.local \
		${GMAKE} install)
	${INSTALL_PROGRAM} ${WRKSRC}/texk/mendexk2.4f/mendex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/texk/jmakeindex/src/jmakeindex \
		${PREFIX}/bin

post-install:
	mktexlsr ${LOCALBASE}/share/texmf.local

pre-clean:
	cd ../../print/teTeX-bin && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
