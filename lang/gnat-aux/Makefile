# $NetBSD: Makefile,v 1.7 2011/12/03 07:28:18 marino Exp $
#

DISTNAME=	gnat-aux-${SNAPSHOT}
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

SNAPSHOT=	20110627
GCC_BRANCH=	4.6
GCC_POINT=	1
LANGS=		c

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake sed flex bison gm4 perl makeinfo bzip2
USE_BUILTIN.iconv=	no
BUILD_DEPENDS+=		autoconf>=2.6:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# Requires bootstrap compiler, which is only available for NetBSD i386/AMD64
# and DragonFly i386/AMD64.  Actually bootstrap compilers for OpenBSD and
# FreeBSD also exist, but native packages will be available for those ports.

ONLY_FOR_PLATFORM=	DragonFly-*-*        \
                  	NetBSD-[5-9]*-i386   \
                  	NetBSD-[5-9]*-x86_64 \
			SunOS-5.*-i386

BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}${OS_VERSION}
THREAD_MODEL=		posix
OS_LABEL4VERS=		[pkgsrc]
BOOTSTRAP_COMPILER=	NOT_REQUIRED
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_TRIPLET=      NOT SET
FULL_GNATGCC=		NOT SET
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin
OLD_EH=			register_frame
REBUILD_LIB=		Rebuild the following library first:


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
.if empty(OS_VERSION:M5.99.*)
   NSUFF=	${OS_VERSION}
.else
   NSUFF=	6.0_DEV
.endif
.if ${MACHINE_ARCH} == "i386"
   OS_LABEL4VERS=	[NetBSD]
   BOOTSTRAP_TRIPLET=	i386-bootstrap-netbsdelf5.1/4.6.0
   BLD_TARGET=		${MACHINE_ARCH}-aux-netbsdelf${NSUFF}
.endif
.if ${MACHINE_ARCH} == "x86_64"
   OS_LABEL4VERS=	[NetBSD64]
   BOOTSTRAP_TRIPLET=	x86_64-bootstrap-netbsd5.1/4.6.0
   BLD_TARGET=		${MACHINE_ARCH}-aux-netbsd${NSUFF}
.endif
BOOTSTRAP_COMPILER=	gnat-bootstrap.${MACHINE_ARCH}.netbsd.tar.bz2
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
.endif



# Let's build this without bash
CONFIG_SHELL=		${TOOLS_PATH.sh}


# define some important directories and files
BUILDDIR=		${WRKDIR}/build
WRKSRC=			${WRKDIR}/gcc-${GCC_BRANCH}-${SNAPSHOT}
PKG_PREFIX=		${PREFIX}
CFG_SCRIPT=		${WRKSRC}/configure
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
MAN7=			fsf-funding.7 gfdl.7 gpl.7
SMAN1=			share/man/man1
SMAN7=			share/man/man7
LPATH=			lib/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
LEPATH=			libexec/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
REVFILE= 		${WRKSRC}/gcc/REVISION
BASELIB=		${LOCALBASE}/lib



# testing if gnatgcc, gnatlink, gnatbind and gnatmake are in standard location
# exists function will NOT expand any variable, so it has to be hard-coded
.if exists(/usr/pkg/bin/gnatgcc)  || exists(/opt/ipp/pkg/bin/gnatgcc)
.if exists(/usr/pkg/bin/gnatbind) || exists(/opt/ipp/pkg/bin/gnatbind)
.if exists(/usr/pkg/bin/gnatlink) || exists(/opt/ipp/pkg/bin/gnatlink)
.if exists(/usr/pkg/bin/gnatmake) || exists(/opt/ipp/pkg/bin/gnatmake)
FULL_GNATGCC=${PREFIX}/bin/gnatgcc
.endif #gnatmake
.endif #gnatlink
.endif #gnatbind
.endif #gnatgcc


.if ${FULL_GNATGCC} == "NOT SET"
# here we know we need to install the bootstrap compiler
INTENDED_COMPILER=BOOTSTRAP
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
DISTFILES= ${DISTNAME}${EXTRACT_SUFX} ${BOOTSTRAP_COMPILER}
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin
.endif


# For pkg maintenance, uncomment to invoke "bmake mdi"
#DISTFILES=${DISTNAME}${EXTRACT_SUFX} \
#  gnat-bootstrap.i386.dragonfly.tar.bz2 \
#  gnat-bootstrap.x86_64.dragonfly.tar.bz2 \
#  gnat-bootstrap.i386.netbsd.tar.bz2 \
#  gnat-bootstrap.x86_64.netbsd.tar.bz2 \
#  gnat-bootstrap.i386.solaris.tar.bz2


# establish ada-aware compiler for use
MY_CONFIGURE_ENV=	CC=${FULL_GNATGCC}
MY_CONFIGURE_ENV+=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	CONFIG_SHELL=${CONFIG_SHELL}
MY_MAKE_ENV=		PATH=${FULL_PATH}
MY_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc


# The standard configuration options
CONFIGURE_ARGS= 	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--program-prefix=gnat
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PKG_PREFIX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads=${THREAD_MODEL}
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-nls


# Automatic package list generation
# lib/libquadmath.* will have to be added if __float128 support is added
# Alternatively, libquadmath support could be intentionally disabled.
GENERATE_PLIST=  cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+= ${FIND} bin/gnat* | ${SORT};
GENERATE_PLIST+= ${FIND} bin/${BLD_TARGET}* | ${SORT};
GENERATE_PLIST+= ${FIND} lib/libiberty.a;
GENERATE_PLIST+= ${FIND} lib/libgcc_s.* \( -type f -or -type l \) | ${SORT};
.if !empty(PKG_OPTIONS:Mcxx)
GENERATE_PLIST+= ${FIND} lib/libsupc++.* \( -type f -or -type l \) | ${SORT};
GENERATE_PLIST+= ${FIND} lib/libstdc++.* \( -type f -or -type l \) | ${SORT};
GENERATE_PLIST+= ${FIND} include/c++/${GCC_BRANCH}.${GCC_POINT}/* -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} share/gcc-${GCC_BRANCH}.${GCC_POINT}/*   -type f | ${SORT} -dr;
.endif
GENERATE_PLIST+= ${FIND} ${LPATH}/*     \( -type f -or -type l \) | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} ${LEPATH}/*    -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} ${SMAN1}/gnat* -type f | ${SORT};
.for k in ${MAN7}
GENERATE_PLIST+= ${FIND} ${SMAN7}/${k};
.endfor



post-extract:
	# Personalize GNAT for each different machine
	@${ECHO} "-=> GNAT AUX ${OS_LABEL4VERS}" > ${REVFILE}

.if ${INTENDED_COMPILER} == "BOOTSTRAP"
	${MKDIR} ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	mv ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}

	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.
	# It is at least 28MB and doesn't come with shared libraries.

.if (${OPSYS} == "NetBSD") && (empty(OS_VERSION:M[5].[0-8]*))
	# Bootstrap compiler malfunctions in NetBSD 6 unless include-fixed
	# directory is removed first.

	${RM} -rf ${BOOTSTRAP_PREFIX}/lib/gcc/${BOOTSTRAP_TRIPLET}/include-fixed
.endif
.endif


pre-configure:
# NetBSD's system compiler is not configured to use dl_iterate_phdr which is
# required to build shared libraries if gnat-aux handles exceptions via
# dl_iterate_phdr.  Therefore this functionality is disabled for NetBSD until
# further notice.  DragonFly introduced this functionality with 2.11, but it's
# possible the shared libraries were built with an earlier compiler in the
# case of an upgrade.  We need to detect this situation and stop the build
# if the libraries need to be rebuilt.
.if ${OPSYS} == "DragonFly"
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
	#late switch of compiler to fool default depends checking
	${SETENV} CC=${FULL_GNATGCC}

	#reset timestamps
	cd ${WRKSRC}; contrib/gcc_update --touch
	${RM} -f ${WRKSRC}/gcc/*/*.info*
	${TOUCH} ${WRKSRC}/gcc/cstamp-h.in

	${MKDIR} ${BUILDDIR}
	cd ${BUILDDIR} && ${SETENV} ${MY_CONFIGURE_ENV} \
	${CFG_SCRIPT} ${CONFIGURE_ARGS}


do-build:
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -j${MAKE_JOBS:U1:Q} all


do-test: build
.if !empty(PKG_OPTIONS:Mtestada)
.if (${OPSYS} == "NetBSD") && (${MACHINE_ARCH} == "x86_64")
	#NetBSD has an exremely small default stacksize of 2MB, which is insufficient
	#for the gnat.dg testsuite (entry_queues test on AMD64 specifically)
	cd ${BUILDDIR} && \
	${ULIMIT_CMD_stacksize} && \
	${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada
.else
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada
.endif
.endif
.if !empty(PKG_OPTIONS:Mtestcxx)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-c++
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-target-libstdc++-v3
.endif
.if !empty(PKG_OPTIONS:Mtestgcc)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-c
.endif


do-install:
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} install-strip \
	DESTDIR=${DESTDIR}



.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
