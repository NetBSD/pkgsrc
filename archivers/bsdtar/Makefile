# $NetBSD: Makefile,v 1.27 2020/03/12 20:50:30 rillig Exp $

.include "../../archivers/libarchive/Makefile.common"
.include "../../mk/bsd.prefs.mk"

PKGNAME=	${DISTNAME:S/libarchive/bsdtar/}
COMMENT=	Fast multi-format tape archiver

# Explicitly do not depend on libtool as this can be used
# as bootstrap dependency.
#USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--enable-bsdtar=static
CONFIGURE_ARGS+=	--disable-bsdcpio
CONFIGURE_ARGS+=	--disable-shared
.if "${OS_VARIANT}" == "chromeos"
CONFIGURE_ARGS+=	--disable-acl
.endif

.include "../../archivers/bzip2/builtin.mk"
.include "../../archivers/xz/builtin.mk"
.include "../../devel/zlib/builtin.mk"
CHECK_BUILTIN.openssl:=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no

.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
CPPFLAGS+=		-I${WRKDIR}/bzip2
LDFLAGS+=		-L${WRKDIR}/bzip2
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
CPPFLAGS+=		-I${WRKDIR}/zlib
LDFLAGS+=		-L${WRKDIR}/zlib
.endif
.if empty(USE_BUILTIN.openssl:M[yY][eE][sS])
CONFIGURE_ARGS+=	--without-openssl
.else
LDFLAGS+=		-lcrypto
.endif
.if empty(USE_BUILTIN.xz:M[yY][eE][sS])
CONFIGURE_ARGS+=	--without-lzma
.endif

FILESDIR.bzip2?=	${.CURDIR}/../../archivers/bzip2/files
FILESDIR.libarchive?=	${.CURDIR}/../../archivers/libarchive/files
FILESDIR.zlib?=		${.CURDIR}/../../devel/zlib/files

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

CHECK_PERMS=		no # avoid circular dependency
CHECK_PORTABILITY=	no # avoid circular dependency

.include "../../mk/bsd.prefs.mk"
.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has windows.h, and configure expects it for MS Windows.
CONFIGURE_ENV+=		ac_cv_header_windows_h=no
.endif

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
