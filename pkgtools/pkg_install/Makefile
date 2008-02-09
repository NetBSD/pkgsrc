# $NetBSD: Makefile,v 1.146 2008/02/09 14:08:05 joerg Exp $

# Notes to package maintainers:
#
# Updating this package does not automatically necessitate bumping
# PKGTOOLS_REQD in bsd.pkg.mk. Do so if and only if there is a critical
# change in the pkg_* tools that pkgsrc relies on for proper operation.

DISTNAME=		pkg_install-${VERSION}
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Package management and administration tools for pkgsrc
#LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		audit-packages-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR:Q}
CONFIGURE_ARGS+=	--with-ftp=${FETCH_CMD:Q}
CONFIGURE_ARGS+=	--with-pax=${PAX:Q}
CONFIGURE_ARGS+=	--with-tar=${TAR:Q}
USE_TOOLS+=		pax:run tar:run gzcat:run

# The following tools are needed by pkg_view and linkfarm.
USE_TOOLS+=		chmod cmp cp env find grep ln mkdir rm rmdir	\
			sed sort touch

USE_FEATURES=		nbcompat

SKIP_AUDIT_PACKAGES=	yes
NO_PKGTOOLS_REQD_CHECK=	yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
PKG_PRESERVE=		yes
CHECK_PERMS=		no

# These are needed to solve a chicken-and-egg problem where pkgsrc uses
# newer features of pkg_install, but older NetBSD installations won't
# support them.  In this case, we explicitly use the native GCC
# compiler to avoid problems with depending on pkgsrc GCC for building
# pkg_install.
#
# We also use the newly built pkg_delete since upgrading from an older
# pkg_install might required features of the new program.
#
USE_NATIVE_GCC=		yes
PKG_CREATE=		${WRKSRC}/create/pkg_create
PKG_DELETE=		${WRKSRC}/delete/pkg_delete

CPPFLAGS+=		-D_LARGEFILE_SOURCE -D_LARGE_FILES
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64

CPPFLAGS+=		-DDEF_UMASK=${DEF_UMASK}

MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
MAKE_ENV+=		OPSYS=${OPSYS:Q}

PKG_DBDIR?=		/var/db/pkg
PKG_INFO=		${PKG_INFO_CMD} -K ${PKG_DBDIR:Q}
PKG_ADMIN=		${PKG_ADMIN_CMD} -K ${PKG_DBDIR:Q}
EGDIR=			${PREFIX}/share/examples/pkg_install

PLIST_SUBST+=		PKG_DBDIR=${PKG_DBDIR:Q}

DEINSTALL_SRC=		# empty
INSTALL_SRC=		${PKGDIR}/INSTALL
FILES_SUBST+=		PKG_DBDIR=${PKG_DBDIR:Q}			\
			PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}		\
			MKDIR=${MKDIR:Q}
MESSAGE_SUBST+=		PKGVULNDIR=${PKG_DBDIR:Q}			\
			EGDIR=${EGDIR:Q}

.include "../../mk/bsd.prefs.mk"

VERSION!=		${AWK} -F '"' '/PKGTOOLS_VERSION/ {print $$2}' \
			${FILESDIR}/lib/version.h

# Make sure the audit-packages files pick up the right tools in the right
# places.
#
SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing paths in scripts.
SUBST_FILES.paths=	audit-packages/Makefile.in
SUBST_SED.paths=	-e 's,_gzcat_,${GZCAT},g'

.include "../../archivers/bzip2/builtin.mk"
.include "../../archivers/libarchive/builtin.mk"
.include "../../devel/zlib/builtin.mk"

.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS]) || \
    empty(USE_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.libarchive=	no
.endif

FILESDIR.bzip2?=	${.CURDIR}/../../archivers/bzip2/files
FILESDIR.libarchive?=	${.CURDIR}/../../archivers/libarchive/files
FILESDIR.zlib?=		${.CURDIR}/../../devel/zlib/files

.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
CPPFLAGS+=	-I${WRKDIR}/bzip2
LDFLAGS+=	-L${WRKDIR}/bzip2
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
CPPFLAGS+=	-I${WRKDIR}/zlib
LDFLAGS+=	-L${WRKDIR}/zlib
.endif
.if empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
CPPFLAGS+=	-I${WRKDIR}/libarchive/libarchive
LDFLAGS+=	-L${WRKDIR}/libarchive/.libs
.endif

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
	@${CP} -R ${FILESDIR.bzip2} ${WRKDIR}/bzip2
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
	@${CP} -R ${FILESDIR.zlib} ${WRKDIR}/zlib
.endif
.if empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
	@${CP} -R ${FILESDIR.libarchive} ${WRKDIR}/libarchive
.endif

pre-configure:
.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
	cd ${WRKDIR}/bzip2 && ${BUILD_MAKE_CMD} libbz2.a
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
	cd ${WRKDIR}/zlib && ${BUILD_MAKE_CMD} libz.a
.endif
.if empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
	cd ${WRKDIR}/libarchive &&					\
	${SETENV} ${_CONFIGURE_SCRIPT_ENV}				\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
		./configure --disable-shared --disable-bsdtar		\
		--disable-dependency-tracking
	cd ${WRKDIR}/libarchive && ${BUILD_MAKE_CMD}
.endif

# XXX Reverse the order that update does things since
# XXX we need pkg_delete built before we can deinstall.
# XXX This should probably be the default order for all packages.
update:
	${MAKE}
	${MAKE} deinstall _UPDATE_RUNNING=YES
	${MAKE} ${UPDATE_TARGET}
	${MAKE} clean

.include "../../mk/bsd.pkg.mk"
