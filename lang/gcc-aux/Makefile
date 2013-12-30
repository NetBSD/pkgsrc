# $NetBSD: Makefile,v 1.13 2013/12/30 01:34:43 marino Exp $
#

PKGNAME=	gcc-aux-${SNAPSHOT}
DISTNAME=	gcc-${GCC_VERSION}
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

SNAPSHOT=	20130411
GCC_BRANCH=	4.7
GCC_POINT=	3
GCC_VERSION=	${GCC_BRANCH}.${GCC_POINT}
LANGS=		c

USE_TOOLS+=		gmake sed:run perl makeinfo bzip2 patch pod2man
USE_BUILTIN.iconv=	no
APPLY_DIFFS=		core

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# Requires bootstrap compiler, which is only available for NetBSD i386/AMD64
# DragonFly i386/AMD64 and SunOS i386  Bootstrap compilers for OpenBSD and
# FreeBSD also exist, but are currently reserved for the native package systems
# of those platforms.

ONLY_FOR_PLATFORM=	DragonFly-*-*        \
			NetBSD-[5-9]*-i386   \
			NetBSD-[5-9]*-x86_64 \
			SunOS-5.1[1-9]*-i386

BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}${OS_VERSION}
THREAD_MODEL=		posix
OS_LABEL4VERS=		[pkgsrc]
BOOTSTRAP_COMPILER=	NOT_REQUIRED
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_TRIPLET=	NOT SET
FULL_GNATGCC=		NOT SET
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/gcc-aux/bin:${PREFIX}/sbin:${PREFIX}/bin
OLD_EH=			register_frame
REBUILD_LIB=		Rebuild the following library first:
STICONV=		${PREFIX}/lib/libiconv.a
STINTL= 		\$${top_builddir}/../intl/libintl.a


.if ${OPSYS} == "DragonFly"
.if ${MACHINE_ARCH} == "i386"
   OS_LABEL4VERS=	[DragonFly]
   BOOTSTRAP_TRIPLET=	i386-bootstrap-dragonfly2.8/4.6.0
.endif
.if ${MACHINE_ARCH} == "x86_64"
   OS_LABEL4VERS=	[DragonFly64]
   BOOTSTRAP_TRIPLET=	x86_64-bootstrap-dragonfly2.8/4.6.0
.endif
BOOTSTRAP_COMPILER=	gnat-bootstrap.${MACHINE_ARCH}.dragonfly.tar.bz2
LINK_HEADER=		/usr/include/sys/link_elf.h
.endif


.if ${OPSYS} == "NetBSD"
.if !empty(OS_VERSION:M6.99.*)
   NSUFF=	7.0_DEV
.else
   NSUFF=	${OS_VERSION}
.endif
# Special handling of clang may be required for all platforms
# but currently this is confirmed only for NetBSD
.if ${PKGSRC_COMPILER} == clang
MY_CONFIGURE_ENV+=	LDFLAGS=-lm
.endif
.if ${MACHINE_ARCH} == "i386"
   OS_LABEL4VERS=	[NetBSD]
   BOOTSTRAP_TRIPLET=	i386-bootstrap-netbsdelf5.1/4.6.0
   BLD_TARGET=		${MACHINE_ARCH}-aux-netbsdelf${NSUFF}
   BOOTSTRAP_COMPILER=	gnat-bootstrap.${MACHINE_ARCH}.netbsd.tar.bz2
.endif
.if ${MACHINE_ARCH} == "x86_64"
   OS_LABEL4VERS=	[NetBSD64]
   BOOTSTRAP_TRIPLET=	x86_64-aux-netbsd6.1/4.7.3
   BLD_TARGET=		${MACHINE_ARCH}-aux-netbsd${NSUFF}
   BOOTSTRAP_COMPILER=	gnat-bootstrap2.${MACHINE_ARCH}.netbsd.tar.bz2
.endif
LINK_HEADER=		/usr/include/link_elf.h
.endif


.if ${OPSYS} == "SunOS"
.if ${MACHINE_ARCH} == "i386"
   OS_LABEL4VERS=	[Solaris]
   BOOTSTRAP_TRIPLET=	i386-bootstrap-solaris5.11/4.6.1
.endif
SOL_OSV=		`expr substr ${OS_VERSION} 3 2`
BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}2.${SOL_OSV}
BOOTSTRAP_COMPILER=	gnat-bootstrap.${MACHINE_ARCH}.solaris.tar.bz2
MY_CONFIGURE_ENV+=	OBJDUMP=/usr/sfw/bin/gobjdump
. if exists(/usr/sfw/bin/gld)
EXTRA_CONFARGS+=	--with-gnu-ld --with-ld=/usr/sfw/bin/gld
. else
EXTRA_CONFARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
. endif
. if exists(/usr/sfw/bin/gas)
EXTRA_CONFARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
. else
EXTRA_CONFARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
. endif
.endif


# define some important directories and files
BUILDDIR=		${WRKDIR}/build
WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
PKG_PREFIX=		${PREFIX}/gcc-aux
CFG_SCRIPT=		${WRKSRC}/configure
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
REVFILE= 		${WRKSRC}/gcc/REVISION
BASELIB=		${PREFIX}/lib



# testing if gcc-aux is already installed - if so, use this compiler along with
# its gnatlink, gnatbind, and gnatmake rather than the older bootstrap versions
.if exists(${LOCALBASE}/gcc-aux/bin/ada)
FULL_GNATGCC=${LOCALBASE}/gcc-aux/bin/ada
.endif


.if ${FULL_GNATGCC} == "NOT SET"
# here we know we need to install the bootstrap compiler
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
DISTFILES+= ${BOOTSTRAP_COMPILER}
SITES.${BOOTSTRAP_COMPILER}=	http://downloads.dragonlace.net/src/
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin
.  if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == "x86_64"
MY_CONFIGURE_ENV+= LD_LIBRARY_PATH=${BOOTSTRAP_PREFIX}/lib
EXTRA_LLP=:${BOOTSTRAP_PREFIX}/lib
.  endif
.endif


# For pkg maintenance, uncomment to invoke "bmake mdi"
#DISTFILES+= \
#  gnat-bootstrap.i386.dragonfly.tar.bz2 \
#  gnat-bootstrap.x86_64.dragonfly.tar.bz2 \
#  gnat-bootstrap.i386.netbsd.tar.bz2 \
#  gnat-bootstrap2.x86_64.netbsd.tar.bz2 \
#  gnat-bootstrap.i386.solaris.tar.bz2


# establish ada-aware compiler for use
MY_CONFIGURE_ENV+=	CC=${FULL_GNATGCC}
MY_CONFIGURE_ENV+=	PATH=${FULL_PATH}
MY_MAKE_ENV=		PATH=${FULL_PATH}
MY_MAKE_ENV+=		ICONVPREFIX=${PREFIX}
MY_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc${EXTRA_LLP}
# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MY_MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MY_MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}


# The standard configuration options
CONFIGURE_ARGS= 	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--prefix=${PKG_PREFIX:Q}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads=${THREAD_MODEL}
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	${EXTRA_CONFARGS}

# Automatic package list generation
GENERATE_PLIST=  cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+= ${FIND} * \( -type f -or -type l \) | ${SORT} -dr;


post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GCC AUX ${OS_LABEL4VERS}" > ${REVFILE}

	# Create new directories in preparation of applying diff files
.if !empty(PKG_OPTIONS:Mcxx)
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
.endif

	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor

	# Update LINK_SPEC to add gcc-aux lib runpath in every binary
	@${ECHO} "Configuring LINK_SPEC runpath"
	@perl -pi -e 's;\@PREFIX\@;${PREFIX};' \
	  ${WRKSRC}/gcc/config/dragonfly.h \
	  ${WRKSRC}/gcc/config/i386/freebsd.h \
	  ${WRKSRC}/gcc/config/i386/netbsd-elf.h

	# Handle static option
.if !empty(PKG_OPTIONS:Mstatic) || ${OPSYS} == "NetBSD"
	@${ECHO} "Reconfiguring GCC Makefile to build compiler statically"
	@${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-static-version
.if empty(PKG_OPTIONS:Mnls)
	@perl -pi -e 's;\@LIBICONV\@;${STICONV};' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.else
	@perl -pi -e 's;\@LIBINTL\@;${STINTL} ${STICONV};' ${WRKSRC}/intl/config.intl.in
	@perl -pi -e 's;\@LIBICONV\@;;' \
	  ${WRKSRC}/gcc/Makefile.in \
	  ${WRKSRC}/libcpp/Makefile.in \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.endif
.endif

.if ${INTENDED_COMPILER} == "BOOTSTRAP"
	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.
	# It is at least 28MB and doesn't come with shared libraries.

	${MKDIR} ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}

	# Bootstrap compiler malfunctions in NetBSD 6 unless include-fixed
	# directory is removed first.  It will eventually cause problems
	# for DragonFly and Solaris as well, so just unconditionally kill it.
	${RM} -rf ${BOOTSTRAP_PREFIX}/lib/gcc/${BOOTSTRAP_TRIPLET}/include-fixed
.endif


pre-configure:
# NetBSD's system compiler is not configured to use dl_iterate_phdr which is
# required to build shared libraries if gnat-aux handles exceptions via
# dl_iterate_phdr.  Therefore the feature requires statically built
# gmp, mpc, mpfr, and iconv libraries in order to build on NetBSD.
# DragonFly introduced this functionality with 2.11, but it's possible the
# shared libraries were built with an earlier compiler in the case of an
# upgrade.  We need to detect this situation on shared library builds and
# stop the build if the libraries need to be rebuilt.
.if ${OPSYS} == "DragonFly" && empty(PKG_OPTIONS:Mstatic)
	@if ${GREP} dl_iterate_phdr ${LINK_HEADER} > /dev/null; then \
	  if ${GREP} ${OLD_EH} ${BASELIB}/libmpc.so > /dev/null; then \
	    ${ERROR_MSG} "${REBUILD_LIB} math/mpcomplex"; \
	    exit 101; \
	  fi; \
	  if ${GREP} ${OLD_EH} ${BASELIB}/libmpfr.so > /dev/null; then \
	    ${ERROR_MSG} "${REBUILD_LIB} math/mpfr"; \
	    exit 102; \
	  fi; \
	  if ${GREP} ${OLD_EH} ${BASELIB}/libgmp.so > /dev/null; then \
	    ${ERROR_MSG} "${REBUILD_LIB} devel/gmp"; \
	    exit 103; \
	  fi; \
	  if ${GREP} ${OLD_EH} ${BASELIB}/libiconv.so > /dev/null; then \
	    ${ERROR_MSG} "${REBUILD_LIB} converters/libiconv"; \
	    exit 104; \
	  fi; \
	fi
.endif


do-configure:
	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${MY_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}


do-build:
	# The unlimited stacksize is for NetBSD64
	cd ${BUILDDIR} && \
	${ULIMIT_CMD_stacksize} && \
	${SETENV} ${MY_MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1:Q} all


do-test: build test-ada test-fortran test-objc test-cxx test-c

test-ada:
.if !empty(PKG_OPTIONS:Mtestsuite) && !empty(PKG_OPTIONS:Mada)
.if (${OPSYS} == "NetBSD") && (${MACHINE_ARCH} == "x86_64")
	# NetBSD has an extremely small default stacksize of 2MB, which is
	# insufficient for the gnat.dg testsuite.
	# specifically: entry_queues test on AMD64
	# Unlimiting stack resources on i386-netbsdelf* will result in
	# failure of gnat.dg/task_stack_align.adb execution test.
	cd ${BUILDDIR} && \
	${ULIMIT_CMD_stacksize} && \
	${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada
.else
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada
.endif
.endif

test-fortran:
.if !empty(PKG_OPTIONS:Mtestsuite) && !empty(PKG_OPTIONS:Mfortran)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-fortran
.endif

test-objc:
.if !empty(PKG_OPTIONS:Mtestsuite) && !empty(PKG_OPTIONS:Mobjc)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-objc
.endif

test-cxx:
.if !empty(PKG_OPTIONS:Mtestsuite) && !empty(PKG_OPTIONS:Mcxx)
	# libstdc++ always ends with error status, so ignore it
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk \
	check-c++ || ${TRUE}
.endif

test-c:
.if !empty(PKG_OPTIONS:Mtestsuite)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-c
.endif


do-install:
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} install-strip \
	DESTDIR=${DESTDIR}



.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
