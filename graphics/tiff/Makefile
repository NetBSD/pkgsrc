# $NetBSD: Makefile,v 1.32 2001/06/10 00:08:45 jlam Exp $

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

USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR}
CONFIGURE_ENV+=	CC="${CC}"

.include "../../mk/bsd.prefs.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"

ZLIBDIR_DEFAULT=	/usr/lib
EVAL_PREFIX+=		ZLIBDIR=zlib

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
CONFIGURE_ENV+=	PREFIX="${PREFIX}"
CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}"
CONFIGURE_ENV+=	ENVOPTS="${CFLAGS} ${CPPFLAGS}"
CONFIGURE_ENV+=	ZLIBDIR="${ZLIBDIR}"
CONFIGURE_ENV+=	BUILDLINK_INCDIR=${BUILDLINK_INCDIR}
CONFIGURE_ENV+=	BUILDLINK_LIBDIR=${BUILDLINK_LIBDIR}

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
