# $NetBSD: Makefile,v 1.48 2000/02/24 00:47:25 tron Exp $
#

DISTNAME=	ghostscript-5.50
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs550/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		http://www.ozemail.com.au/~geoffk/pdfencrypt/ \
		ftp://ftp.sbs.de/pub/graphics/ghostscript/pcl3/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV} ${HPDJ_DRV} ${PDF_SEC}

PATCH_SITES=	http://www.cs.wisc.edu/~ghost/aladdin/relnotes/gs550/
PATCHFILES=	990524.txt 990220c.txt 990220b.txt 990220a.txt 990220.txt \
		990120a.txt 990120.txt 990117.txt 990115a.txt 981222.txt \
		981221.txt 981220.txt

MAINTAINER=	explorer@netbsd.org
HOMEPAGE=	http://www.cs.wisc.edu/~ghost/index.html

BUILD_DEPENDS=	${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b:../../graphics/jpeg:extract
BUILD_DEPENDS+=	unzip:../../archivers/unzip
DEPENDS=	png>=1.0.3:../../graphics/png

USE_X11=	yes

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	${DISTNAME:C/-.*$//}
EXTRACT_ONLY=	${GS_SOURCES} ${HPDJ_DRV}
ALL_TARGET=	std
MAKEFILE=	unix-gcc.mak
MAKE_ENV+=	MAKEOBJDIR=. prefix=${PREFIX}
.if ${OPSYS} == "SunOS"
LDFLAGS+=	-L${LOCALBASE}/bsd/lib
.elif ${OPSYS} == NetBSD && ${MACHINE_ARCH} == arm32
CFLAGS=
.endif
.if defined(PAPERSIZE) && (${PAPERSIZE} == "A4" || ${PAPERSIZE} == "a4")
MAKE_FLAGS+=	-DA4
.endif
WRKSRC=		${WRKDIR}/gs5.50

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

# Additional driver for several HP deskjets
HPDJ_VER=	2.6
HPDJ_DRV=	hpdj-${HPDJ_VER}.tar.gz

# PostScript source to decode encrypted PDF files
PDF_SEC=	pdf_sec.ps

SCRIPT_SUFFIX=	.batch

post-extract:
	${GTAR} -xf ${WRKDIR}/hpdj-${HPDJ_VER}/hpdj.tar -C ${WRKSRC}
	${RM} -f ${WRKSRC}/jpeg
	${LN} -s ${BUILD_ROOT}/graphics/jpeg/${WRKDIR:T}/jpeg-6b ${WRKSRC}/jpeg
	cd ${WRKSRC} && unzip -uLa ${_DISTDIR}/${HP850_DRV}
	${RM} -f ${WRKSRC}/${PDF_SEC}
	${LN} -s ${_DISTDIR}/${PDF_SEC} ${WRKSRC}/${PDF_SEC}

pre-patch:
	@${RM} -f ${WRKSRC}/lib ${WRKSRC}/src
	@${LN} -s . ${WRKSRC}/lib
	@${LN} -s . ${WRKSRC}/src
	@${PATCH} ${PATCH_ARGS} < ${WRKSRC}/zmedia2.c-5.50.diff
	@${CAT} ${WRKSRC}/contrib.mak-5.50.add >>${WRKSRC}/contrib.mak

post-patch:
	@${RM} -f ${WRKSRC}/lib ${WRKSRC}/src

do-configure:
	@${SETENV} WRKSRC=${WRKSRC} PREFIX=${PREFIX} \
		${SH} ${SCRIPTDIR}/configure${SCRIPT_SUFFIX}

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			${GTAR} -xzf ${_DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			${GTAR} -xzf ${_DISTDIR}/${GS_FONTS_OTHER})

post-install:
	strip ${PREFIX}/bin/gs

pre-clean:
	@cd ../../graphics/jpeg && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
