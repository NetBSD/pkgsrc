# $NetBSD: Makefile,v 1.23 2000/01/06 01:25:22 wiz Exp $

DISTNAME=	tiff-v3.5.4
PKGNAME=	tiff-3.5.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.libtiff.org/ \
		ftp://ftp.onshore.com/pub/libtiff/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
# need DISTFILES above for adding lzw-files to it, if USE_GIF is defined
# in mk.conf

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libtiff.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg

USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ZLIBDIR=	${LOCALBASE}/lib
DEPENDS+=	zlib-*:../../devel/zlib
.else
ZLIBDIR=	/usr/lib
.endif

.if defined(USE_GIF)
DISTFILES+=	libtiff-lzw-compression-kit.tar.gz

pre-build:
	cd ${WRKSRC} \
		&& ${CP} ../libtiff-lzw-compression-kit/tif_dir.c libtiff \
		&& ${CP} ../libtiff-lzw-compression-kit/tif_lzw.c libtiff
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
