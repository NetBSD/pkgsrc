# $NetBSD: Makefile,v 1.216 2016/02/25 17:25:05 jperkin Exp $

# Notes to package maintainers:
#
# Updating this package does not automatically necessitate bumping
# PKGTOOLS_REQD in bsd.pkg.mk. Do so if and only if there is a critical
# change in the pkg_* tools that pkgsrc relies on for proper operation.

PKGNAME=		pkg_install-${VERSION}
CATEGORIES=		pkgtools

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		Package management and administration tools for pkgsrc
LICENSE=		modified-bsd

BOOTSTRAP_PKG=	yes
SKIP_LICENSE_CHECK=	yes

CONFLICTS+=		audit-packages-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-pkgdbdir=${PKG_DBDIR}

USE_FEATURES=		nbcompat

NBCOMPAT_CONFIGURE_ARGS+=	--enable-bsd-getopt --enable-db

SKIP_AUDIT_PACKAGES=	yes
NO_PKGTOOLS_REQD_CHECK=	yes
PKG_PRESERVE=		yes
CHECK_PERMS=		no

# These are needed to solve a chicken-and-egg problem where pkgsrc uses
# newer features of pkg_install, but older NetBSD installations won't
# support them.  In this case, we explicitly use the native GCC
# compiler to avoid problems with depending on pkgsrc GCC for building
# pkg_install.
#
# We also use the newly built pkg_{add,create,delete} since upgrading
# from an older pkg_install might required features of the new
# program, provided that we are not cross-compiling.  (XXX If we are
# cross-compiling, we should maybe have a host build dependency on
# ourselves...)
#
# Note that the definitions are only overriden for the phases that are
# supposed to use them.  pkg_admin pmatch might be used when looking for
# dependencies. If that is ever changed in a incompatible way, this has to
# be rethought.
USE_NATIVE_GCC=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2's strings.h defines strcasecmp with
# "unsigned size_t". We cannot use -Werror for net/libfetch.
MAKE_FLAGS+=	NOGCCERROR=yes
.endif

.if defined(_PKGSRC_BARRIER) && empty(USE_CROSS_COMPILE:M[yY][eE][sS])
PKG_ADD_CMD=		${WRKSRC}/add/pkg_add
PKG_CREATE_CMD=		${WRKSRC}/create/pkg_create
PKG_DELETE_CMD=		${WRKSRC}/delete/pkg_delete
#
#  Special case for dependency checking in 'non-bootstrap' builds:
#  don't redefine 'pkg_info' if it already exists.
#
.  if defined(PKG_INFO_CMD) && !exists(${PKG_INFO_CMD})
PKG_INFO_CMD=		${WRKSRC}/info/pkg_info
.  endif
.endif

CPPFLAGS+=		-D_LARGEFILE_SOURCE -D_LARGE_FILES
CPPFLAGS+=		-D_FILE_OFFSET_BITS=64

CPPFLAGS+=		-DDEF_UMASK=${DEF_UMASK}

MAKE_ENV+=		PKGSRC_MACHINE_ARCH=${MACHINE_ARCH}
MAKE_ENV+=		OPSYS=${OPSYS}
MAKE_ENV+=		CATMAN_SECTION_SUFFIX=${CATMAN_SECTION_SUFFIX:Q}
MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

PKG_DBDIR?=		/var/db/pkg
EGDIR=			${PREFIX}/share/examples/pkg_install

PLIST_SUBST+=		PKG_DBDIR=${PKG_DBDIR}

DEINSTALL_SRC=		# empty
INSTALL_SRC=		${PKGDIR}/INSTALL
FILES_SUBST+=		PKG_DBDIR=${PKG_DBDIR}			\
			PKG_TOOLS_BIN=${PKG_TOOLS_BIN:Q}	\
			MKDIR=${MKDIR:Q}
MESSAGE_SUBST+=		PKGVULNDIR=${PKG_DBDIR}			\
			EGDIR=${EGDIR}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mclang*)
MAKE_FLAGS+=		ACTIVE_CC=clang
.endif

VERSION!=		${AWK} '/PKGTOOLS_VERSION/ {print $$3}' \
			${FILESDIR}/lib/version.h

# raw format appeared in libarchive 2.8.
BUILDLINK_API_DEPENDS.libarchive+=	libarchive>=2.8.0

.include "../../archivers/bzip2/builtin.mk"
.include "../../archivers/xz/builtin.mk"
.include "../../archivers/libarchive/builtin.mk"
.include "../../devel/zlib/builtin.mk"
.include "../../security/openssl/builtin.mk"

.include "options.mk"

.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-ssl

.include "../../security/openssl/buildlink3.mk"
.endif

.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS]) || \
    empty(USE_BUILTIN.zlib:M[yY][eE][sS])
USE_BUILTIN.libarchive=	no
.endif

FILESDIR.bzip2?=	${.CURDIR}/../../archivers/bzip2/files
FILESDIR.libarchive?=	${.CURDIR}/../../archivers/libarchive/files
FILESDIR.zlib?=		${.CURDIR}/../../devel/zlib/files
FILESDIR.libfetch?=	${.CURDIR}/../../net/libfetch/files
FILESDIR.netpgpverify?=	${.CURDIR}/../../security/netpgpverify/files

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

# Until we support pkgsrc openssl at bootstrap time, disable it completely
# if asked to avoid the builtin.
.  if empty(USE_BUILTIN.openssl:M[Yy][Ee][Ss])
LIBARCHIVE_CONFIGURE_ARGS+=	--without-openssl
.  endif

# Only use XZ if we actually have builtin support for it. Some systems
# install the header, but without usable library or prefer to not use
# the system version, so give them some control.
.  if empty(USE_BUILTIN.xz:M[Yy][Ee][Ss])
LIBARCHIVE_CONFIGURE_ARGS+=	--without-lzma
.  endif

LIBARCHIVE_LIBS=	${SED} -n -e 's/^Libs.private://p' \
    ${WRKDIR}/libarchive/build/pkgconfig/libarchive.pc 2>/dev/null || echo
LIBS+=		${LIBARCHIVE_LIBS:sh}

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/libarchive/build/autoconf/config.guess \
			${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/libarchive/build/autoconf/config.sub \
			${WRKSRC}/config.sub

CPPFLAGS.Cygwin+=	-DLIBARCHIVE_STATIC

# Make sure that the linker used our static library instead of the
# (outdated) dynamic library "/usr/lib/libarchive.dylib".
LDFLAGS.Darwin+=	-Wl,-search_paths_first

# workaround for pkg/45491
CONFIGURE_ENV.SunOS+=	ac_cv_header_ext2fs_ext2_fs_h=no

# Hack to make sure that the libarchive version is replaced
pre-configure: config-guess-override config-sub-override
.endif
CPPFLAGS+=	-I${WRKDIR}/libfetch
LDFLAGS+=	-L${WRKDIR}/libfetch
# Avoid duplicate and conflicting headers, pull in any we need
# directly with <netpgpgverify/*.h>
CPPFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}/netpgpverify

CONFIGURE_ENV+=	LIBS=${LIBS:Q}

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
	@${CP} -R ${FILESDIR.libfetch} ${WRKDIR}/libfetch
	@${CP} -R ${FILESDIR.netpgpverify} ${WRKDIR}/netpgpverify

pre-configure:
.if empty(USE_BUILTIN.bzip2:M[yY][eE][sS])
	cd ${WRKDIR}/bzip2 && ${BUILD_MAKE_CMD} libbz2.a
.endif
.if empty(USE_BUILTIN.zlib:M[yY][eE][sS])
	cd ${WRKDIR}/zlib && ${BUILD_MAKE_CMD} libz.a
.endif
.if empty(USE_BUILTIN.libarchive:M[yY][eE][sS])
	cd ${WRKDIR}/libarchive && ${SETENV} ${_CONFIGURE_SCRIPT_ENV}	\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ./configure	\
		--disable-bsdcpio --disable-bsdtar --disable-shared	\
		--disable-dependency-tracking --without-expat		\
		--without-iconv --without-lzo2 --without-nettle		\
		--without-xml2	\
		${LIBARCHIVE_CONFIGURE_ARGS}
	cd ${WRKDIR}/libarchive && ${BUILD_MAKE_CMD}
.endif
	cd ${WRKDIR}/libfetch && ${TOUCH} fetch.cat3 &&			\
		${SETENV} ${MAKE_ENV} ${BSD_MAKE_ENV}			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS}	\
			-f ${MAKE_FILE} depend all
	cd ${WRKDIR}/netpgpverify &&					\
	${SED} -e '/zlib/d' Makefile.lib.in >Makefile.in &&		\
	${RM} -f bzlib.h zlib.h &&					\
	${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ./configure &&		\
	${SETENV} ${MAKE_ENV} ${BSD_MAKE_ENV} ${MAKE_PROGRAM}		\
		${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} -f ${MAKE_FILE} all

# XXX Reverse the order that update does things since
# XXX we need pkg_delete built before we can deinstall.
# XXX This should probably be the default order for all packages.
update:
	${MAKE}
	${MAKE} deinstall _UPDATE_RUNNING=YES
	${MAKE} ${UPDATE_TARGET}
	${MAKE} clean

update-catpages:
	for f in lib/pkgsrc.7 add/pkg_add.1 admin/pkg_admin.1 \
	    create/pkg_create.1 delete/pkg_delete.1 info/pkg_info.1 \
	    lib/pkg_summary.5 lib/pkgsrc.7; do \
		nroff -mdoc ${FILESDIR}/$$f > \
		    ${FILESDIR}/$${f%%.[157]}.cat; \
	done
	nroff -mdoc ${FILESDIR}/lib/pkg_install.conf.5.in > \
	    ${FILESDIR}/lib/pkg_install.conf.cat.in

.include "../../mk/bsd.pkg.mk"
