# $NetBSD: Makefile,v 1.52 2004/04/24 18:24:56 tv Exp $

DISTNAME=	tiff-v3.6.1
PKGNAME=	tiff-3.6.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/ \
		http://libtiff.maptools.org/dl/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
# need DISTFILES above for adding lzw-files to it if USE_GIF is defined
# in mk.conf
DISTFILES+=	TIFFTechNote2.html
# It is in CVS for Release-v3-6-1, but accidently excluded from distribution.
SITES_TIFFTechNote2.html=	${MASTER_SITE_LOCAL:=tiff/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.remotesensing.org/libtiff/
COMMENT=	Library and tools for reading and writing TIFF data files

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# use DIST_SUBDIR because TIFFTechNote2.html could be changed later
DIST_SUBDIR=	${PKGNAME_NOREV}

BUILD_DEFS+=	USE_GIF

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR} --prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin)
USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL.OpenWindows
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL.OpenWindows
.endif

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/TIFFTechNote2.html ${WRKSRC}/html/

.if defined(USE_GIF)
LZW_VERSION=	1.5
DISTFILES+=	libtiff-lzw-compression-kit-${LZW_VERSION}.tar.gz
EXTRACT_ONLY+=	libtiff-lzw-compression-kit-${LZW_VERSION}.tar.gz
LZWWRKDIR=	${WRKDIR}/libtiff-lzw-compression-kit-${LZW_VERSION}
pre-patch:
	${CP} ${LZWWRKDIR}/tif_lzw.c ${WRKSRC}/libtiff
.endif

CPPFLAGS+=	-Dunix
CONFIGURE_ENV+=	PREFIX="${PREFIX}"
CONFIGURE_ENV+=	ENVOPTS="${CFLAGS} ${CPPFLAGS}"

INSTALLATION_DIRS=	share/doc/html

# reference correct relative man page when using .so;
# libtoolize build of TIFF tools
post-patch:
	${MV} ${WRKSRC}/man/Makefile.in ${WRKSRC}/man/Makefile.in.in
	${SED}	-e "s,\$${MANDIR}\(.*\)\.\([0-9]\).,${PREFIX}/man/man\2/\1.\2,g" \
		-e "s,\$${MANDIR}\(.*\)\.\([0-9]\),${PREFIX}/man/man\2/\1.\2,g" \
		${WRKSRC}/man/Makefile.in.in  > ${WRKSRC}/man/Makefile.in
	${MV} ${WRKSRC}/tools/Makefile.in ${WRKSRC}/tools/Makefile.in.in
	${SED}	-e "s,\(\$${CC} -o\),\$${LIBTOOL} \1,g" \
		${WRKSRC}/tools/Makefile.in.in  > ${WRKSRC}/tools/Makefile.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
