# $NetBSD: Makefile,v 1.22 1999/10/08 21:14:32 jlam Exp $

DISTNAME=	tiff-v3.5.2
PKGNAME=	tiff-3.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libtiff.org/ \
		ftp://ftp.onshore.com/pub/libtiff/

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
