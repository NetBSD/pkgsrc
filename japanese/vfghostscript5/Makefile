# $NetBSD: Makefile,v 1.1.1.1 1999/09/03 06:14:16 sakamoto Exp $
#

DISTNAME=	ja-vfghostscript-5.50
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs550/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		http://www.erdw.ethz.ch/~bonk/ftp/gs-driver-distrib/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/
MASTER_SITES+=  ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
                ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://ftp.uu.net/graphics/png/src/ \
		ftp://ftp.uu.net/graphics/jpeg/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/ \
		http://www.ldl.jaist.ac.jp/~akr/nonresearch/free-software/ghostscript/ \
		http://www.jaist.ac.jp/~daisuke/Linux/gs/gs5/Original-sources/OLD/ \
		http://www.rd.nacsis.ac.jp/~katayama/homepage/ghostscript/jpdf/\
												http://itohws03.ee.noda.sut.ac.jp/~matsuda/VFlib-FT/ \
		http://www.bpe.es.osaka-u.ac.jp/~watanabe/ \
		http://www.bukka.p.chiba-u.ac.jp/~ohmori/gs/ \
		ftp://ftp.iijnet.or.jp/humbleSoft/pub/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${PDF_SEC} gs5.50-vflib-1.0.tar.gz
DISTFILES+=     gdevlips-2.3.3.tar.gz gdevmjc-0.8.tar.gz gdevrpdl.tar.gz \
                gdev10v.tar.gz dmprt-2.01.tar.gz gdevalps-0.1.tar.gz

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.cs.wisc.edu/~ghost/index.html

BUILD_DEPENDS=	${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b:../../graphics/jpeg:extract \
		unzip:../../archivers/unzip
DEPENDS=	png-1.0.3:../../graphics/png \
		ja-vflib-2.24.2:../../japanese/vflib \
		ghostscript-5.50:../../print/ghostscript5

.include "../../mk/bsd.prefs.mk"

EXTRACT_ONLY=	${GS_SOURCES} gs5.50-vflib-1.0.tar.gz
EXTRACT_ONLY+=	gdevlips-2.3.3.tar.gz gdevmjc-0.8.tar.gz gdevrpdl.tar.gz \
                gdev10v.tar.gz dmprt-2.01.tar.gz gdevalps-0.1.tar.gz
WRKSRC=		${WRKDIR}/gs5.50
MAKEFILE=	unix-gcc.mak
ALL_TARGET=	std
MAKE_ENV+=	MAKEOBJDIR=.
.if ${OPSYS} == "SunOS"
MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}" XLDFLAGS="-Wl,-R${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/bsd/lib -L${LOCALBASE}/bsd/lib"
.else
MAKE_FLAGS=	prefix=${PREFIX} CFLAGS="${CFLAGS}" XLDFLAGS="-Wl,-R${LOCALBASE}/lib -Wl,-R${X11BASE}/lib"
.endif

GS_SOURCES=	ghostscript-5.50.tar.gz
GS_SOURCES+=	ghostscript-5.50gnu.tar.gz
#  Note: the following two are special files.  In the 5.50 directory
#  on the FTP site, there are symlinks:
#        ghostscript-fonts-other-5.50.tar.gz ->
#               ../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
GS_FONTS_STD=	ghostscript-fonts-std-5.10a.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz

# Additional driver HP 850, see http://www.erdw.ethz.ch/~bonk/hp850/hp850.html
HP850_DRV=	hp8xxs13.zip

# PostScript source to decode encrypted PDF files
PDF_SEC=	pdf_sec.ps

.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
PAPERSIZE_DEF=	-DA4
.endif

SCRIPT_SUFFIX=	.batch
SCRIPTS_ENV+= CAT="${CAT}" CP="${CP}" MV="${MV}" \
		MKDIR="${MKDIR}" SED="${SED}" TOUCH="${TOUCH}"

post-extract:
	${LN} -s ${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b ${WRKSRC}/jpeg
	cd ${WRKSRC} && unzip -uLa ${DISTDIR}/${HP850_DRV}
	${CP} ${DISTDIR}/${PDF_SEC} ${WRKSRC}
	
pre-patch:
	cd ${WRKDIR} ; ${PATCH} -s -p0 < gs5.50-vflib-1.0/gs5.50-vflib-1.0.diff 
	cd ${WRKDIR}/gdevmjc-0.8; ${PATCH} -s -p0 < ${FILESDIR}/gdevmjc.c.patch
	cd ${WRKDIR}/gdevmjc-0.8; ${PATCH} -s -p0 < ${FILESDIR}/mjc.dev.patch

do-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/dev_copy${SCRIPT_SUFFIX}
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure${SCRIPT_SUFFIX}

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${PAPERSIZE_DEF} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

GSINST_DIR=	${PREFIX}/share/ghostscript/5.50vflib

post-install:
	strip ${PREFIX}/bin/vfgs
	@${SETENV} ${SCRIPTS_ENV} \
		DOC_DIR=${GSINST_DIR}/doc GSINST_DIR=${GSINST_DIR} \
		${SH} ${SCRIPTDIR}/post_install${SCRIPT_SUFFIX}

pre-clean:
	@cd ../../graphics/jpeg && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
