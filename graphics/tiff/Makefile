# $NetBSD: Makefile,v 1.30 2001/05/03 13:22:50 skrll Exp $

DISTNAME=	tiff-v3.5.5
PKGNAME=	tiff-3.5.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.libtiff.org/ \
		ftp://ftp.onshore.com/pub/libtiff/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
# need DISTFILES above for adding lzw-files to it if USE_GIF is defined
# in mk.conf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libtiff.org/
COMMENT=	library and tools for reading and writing TIFF data files

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR}
CONFIGURE_ENV+=	CC="${CC}"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
ZLIBDIR=	${LOCALBASE}/lib
DEPENDS+=	zlib-*:../../devel/zlib
.else
ZLIBDIR=	/usr/lib
.endif

.if defined(USE_GIF)
DISTFILES+=	libtiff-lzw-compression-kit-1.1.tar.gz
LZWWRKDIR=	${WRKDIR}/libtiff-lzw-compression-kit

post-patch:
	${MV} ${LZWWRKDIR}/Makefile ${LZWWRKDIR}/Makefile.orig
	${SED} "s@TIFF_SRC_DIR = /tmp/libtiff@TIFF_SRC_DIR = ../${DISTNAME}@" \
		${LZWWRKDIR}/Makefile.orig > ${LZWWRKDIR}/Makefile
	cd ${LZWWRKDIR} && make install
.endif

CPPFLAGS+=	-Dunix
CONFIGURE_ENV+=	PREFIX="${PREFIX}" LOCALBASE="${LOCALBASE}" \
		ENVOPTS="${CFLAGS} ${CPPFLAGS}" ZLIBDIR="${ZLIBDIR}"

pre-patch:
	# reference correct relative man page when using .so
	#
	${MV} ${WRKSRC}/man/Makefile.in ${WRKSRC}/man/Makefile.in.in
	${SED}	-e "s,\$${MANDIR}\(.*\)\.\([0-9]\).,\1.\2,g" \
		-e "s,\$${MANDIR}\(.*\)\.\([0-9]\),\1.\2,g" \
		${WRKSRC}/man/Makefile.in.in  > ${WRKSRC}/man/Makefile.in

	# libtoolize build of TIFF tools
	#
	${MV} ${WRKSRC}/tools/Makefile.in ${WRKSRC}/tools/Makefile.in.in
	${SED}	-e "s,\(\$${CC} -o\),\$${LIBTOOL} \1,g" \
		${WRKSRC}/tools/Makefile.in.in  > ${WRKSRC}/tools/Makefile.in

.include "../../mk/bsd.pkg.mk"
