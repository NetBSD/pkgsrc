# $NetBSD: Makefile,v 1.11 1998/04/15 10:38:45 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1997/10/13 11:22:43 asami Exp
#

DISTNAME=	ghostscript-5.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/aladdin/gs510/ \
		ftp://ftp.cs.wisc.edu/ghost/aladdin/fonts/ \
		ftp://bonk.ethz.ch/gs-driver-distrib/
DISTFILES=	${GS_SOURCES} ${GS_FONTS_STD} ${GS_FONTS_OTHER} \
		${HP850_DRV}

MAINTAINER=	explorer@netbsd.org

BUILD_DEPENDS=	${PORTSDIR}/graphics/jpeg/${WRKDIR:T}/jpeg-6a:${PORTSDIR}/graphics/jpeg:extract \
		${PORTSDIR}/graphics/png/${WRKDIR:T}/libpng-0.96:${PORTSDIR}/graphics/png:extract \
		unzip:${PORTSDIR}/archivers/unzip

MAKE_ENV=	PORTSDIR=${PORTSDIR}
EXTRACT_ONLY=	${GS_SOURCES}
WRKSRC=		${WRKDIR}/gs5.10
MAKEFILE=	unix-gcc.mak
MAKE_FLAGS=	prefix=${PREFIX} zlibc_=-lz CFLAGS="${CFLAGS}" -f
MAN1=		gs.1 pdf2dsc.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

GS_SOURCES=	ghostscript-5.10.tar.gz
GS_SOURCES+=	ghostscript-5.10gnu.tar.gz
#  Note: the following two are special files.  In the 5.10 directory
#  on the FTP site, there are symlinks:
#        ghostscript-fonts-other-5.10.tar.gz ->
#               ../fonts/ghostscript-fonts-other-4.40.tar.gz
#  To avoid unnecessarily downloading distfiles, do not change these
#  when upgrading the port unless the symlinks/files really change.
GS_FONTS_STD=	ghostscript-fonts-std-4.0.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-4.40.tar.gz

# Additional driver HP 850, see http://bonk.ethz.ch/hp850/hp850.html
HP850_DRV=	hp850.zip

post-extract:
	${TOUCH} ${WRKSRC}/adler32.c
	${TOUCH} ${WRKSRC}/deflate.c
	${TOUCH} ${WRKSRC}/trees.c
	${TOUCH} ${WRKSRC}/adler32.o
	${TOUCH} ${WRKSRC}/deflate.o
	${TOUCH} ${WRKSRC}/trees.o
	ln -s ${PORTSDIR}/graphics/jpeg/${WRKDIR:T}/jpeg-6a ${WRKSRC}/jpeg-6a
	ln -s ${PORTSDIR}/graphics/png/${WRKDIR:T}/libpng-0.96 ${WRKSRC}/libpng
	cd ${WRKSRC} && unzip -La ${DISTDIR}/${HP850_DRV}

do-configure:
.if defined(BATCH)
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure.batch
.else
	@${SETENV} PORTSDIR=${PORTSDIR} WRKSRC=${WRKSRC} \
		${SH} ${SCRIPTDIR}/configure
.endif

do-build:
	@(paper=""; \
	case X"${PAPERSIZE}" in \
	X[aA]4) \
		paper="-DA4"; \
		${ECHO_MSG} "Using $$paper to set default paper size to A4."; \
		;; \
	*) \
		${ECHO_MSG} "Using default Letter paper size (Set PAPERSIZE=A4 for A4 paper size)."; \
		;; \
	esac; \
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} $$paper ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

pre-install:
	@${MKDIR} ${PREFIX}/share/ghostscript ${PREFIX}/bin ${PREFIX}/man/man1
	(cd ${PREFIX}/share/ghostscript ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_STD})
	(cd ${PREFIX}/share/ghostscript/fonts ; \
			tar -xzf ${DISTDIR}/${GS_FONTS_OTHER})

post-install:
	strip ${PREFIX}/bin/gs

pre-clean:
	@cd ${PORTSDIR}/graphics/jpeg && ${MAKE} clean
	@cd ${PORTSDIR}/graphics/png && ${MAKE} clean

.include "../../mk/bsd.pkg.mk"
