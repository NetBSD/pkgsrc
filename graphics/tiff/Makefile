# $NetBSD: Makefile,v 1.48 2003/10/03 15:38:46 salo Exp $

DISTNAME=	tiff-v3.5.7
PKGNAME=	tiff-3.5.7
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/libtiff/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
# need DISTFILES above for adding lzw-files to it if USE_GIF is defined
# in mk.conf

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libtiff.org/
COMMENT=	Library and tools for reading and writing TIFF data files

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--noninteractive --site=${FILESDIR} --prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if !empty(X11BASE:M*openwin)
USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL.OpenWindows
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL.OpenWindows
.endif

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
	${SED}	-e "s,\$${MANDIR}\(.*\)\.\([0-9]\).,${PREFIX}/man/man\2/\1.\2,g" \
		-e "s,\$${MANDIR}\(.*\)\.\([0-9]\),${PREFIX}/man/man\2/\1.\2,g" \
		${WRKSRC}/man/Makefile.in.in  > ${WRKSRC}/man/Makefile.in

	# libtoolize build of TIFF tools
	#
	${MV} ${WRKSRC}/tools/Makefile.in ${WRKSRC}/tools/Makefile.in.in
	${SED}	-e "s,\(\$${CC} -o\),\$${LIBTOOL} \1,g" \
		${WRKSRC}/tools/Makefile.in.in  > ${WRKSRC}/tools/Makefile.in

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
