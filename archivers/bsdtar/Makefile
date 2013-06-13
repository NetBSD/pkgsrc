# $NetBSD: Makefile,v 1.19 2013/06/13 16:25:19 jperkin Exp $
#

DISTNAME=	bsdtar-2.8.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libarchive/
COMMENT=	Fast multi-format tape archiver

GNU_CONFIGURE=	yes
# Explicitly do not depend on libtool as this can be used
# as bootstrap dependency.
#
#USE_LIBTOOL=	yes

.include "../../archivers/bzip2/builtin.mk"
.include "../../devel/zlib/builtin.mk"

.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
CPPFLAGS+=	-I${WRKDIR}/bzip2
LDFLAGS+=	-L${WRKDIR}/bzip2
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
CPPFLAGS+=	-I${WRKDIR}/zlib
LDFLAGS+=	-L${WRKDIR}/zlib
.endif

FILESDIR.bzip2?=	${.CURDIR}/../../archivers/bzip2/files
FILESDIR.libarchive?=	${.CURDIR}/../../archivers/libarchive/files
FILESDIR.zlib?=		${.CURDIR}/../../devel/zlib/files

CONFIGURE_ARGS+=	--enable-bsdtar=static --disable-cpio \
			--disable-shared --without-xml2 --without-expat \
			--without-openssl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
	${RUN}${CP} -R ${FILESDIR.bzip2} ${WRKDIR}/bzip2
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
	${RUN}${CP} -R ${FILESDIR.zlib} ${WRKDIR}/zlib
.endif
	${RUN}${CP} -R ${FILESDIR.libarchive} ${WRKSRC}

pre-configure:
.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
	cd ${WRKDIR}/bzip2 && ${BUILD_MAKE_CMD} libbz2.a
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
	cd ${WRKDIR}/zlib && ${BUILD_MAKE_CMD} libz.a
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdtar ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tar/bsdtar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
