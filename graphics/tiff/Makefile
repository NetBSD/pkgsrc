# $NetBSD: Makefile,v 1.39.2.2 2002/06/21 23:05:26 jlam Exp $

DISTNAME=	tiff-v3.5.7
PKGNAME=	tiff-3.5.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.libtiff.org/ \
		ftp://ftp.remotesensing.org/pub/libtiff/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
# need DISTFILES above for adding lzw-files to it if USE_GIF is defined
# in mk.conf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libtiff.org/
COMMENT=	Library and tools for reading and writing TIFF data files

USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR} --prefix=${PREFIX}
CONFIGURE_ENV+=	CC="${CC}"

USE_BUILDLINK2=	# defined

.include "../../mk/bsd.prefs.mk"

.if defined(USE_GIF)
LZW_VERSION=	1.3
DISTFILES+=	libtiff-lzw-compression-kit-${LZW_VERSION}.tar.gz
LZWWRKDIR=	${WRKDIR}/libtiff-lzw-compression-kit-${LZW_VERSION}

post-patch:
	${CP} ${LZWWRKDIR}/tif_lzw.c ${WRKSRC}/libtiff
.endif

CPPFLAGS+=	-Dunix
CONFIGURE_ENV+=	PREFIX="${PREFIX}"
CONFIGURE_ENV+=	ENVOPTS="${CFLAGS} ${CPPFLAGS}"

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

.if defined(HAVE_OPENWINDOWS)
INSTALL_FILE=	${WRKDIR}/INSTALL
DEINSTALL_FILE=	${INSTALL_FILE}

pre-build:
	@${SED} -e 's#@LN@#${LN}#g' \
	  -e 's#@MV@#${MV}#g' \
	  -e 's#@PREFIX@#${PREFIX}#g' \
	  -e 's#@X11BASE@#${X11BASE}#g' \
	  ${PKGDIR}/INSTALL.OpenWindows >${INSTALL_FILE}

pre-install:
	${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
