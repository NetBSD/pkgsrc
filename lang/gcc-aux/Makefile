# $NetBSD: Makefile,v 1.17 2014/05/02 15:54:16 marino Exp $
#

PKGNAME=	gcc-aux-${SNAPSHOT}
DISTNAME=	gcc-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

.include "Makefile.version"
.include "Makefile.testsuite"
.include "../../mk/bsd.prefs.mk"
.include "options.mk"

LANGS=		c ada c++
USE_TOOLS+=	gmake sed:run perl makeinfo bzip2 patch pod2man tar
APPLY_DIFFS=	core ada cxx

# Requires bootstrap compiler, which is only available for on selected systems
# Disable SunOS for now until multilib version can be built and tested.

ONLY_FOR_PLATFORM=	DragonFly-*-*        \
			FreeBSD-*-i386       \
			FreeBSD-*-x86_64     \
			NetBSD-[5-9]*-i386   \
			NetBSD-[5-9]*-x86_64

#			SunOS-5.1[1-9]*-i386
#			gnat-bootstrap.i386.solaris.tar.bz2

GARCH=			${MACHINE_ARCH:S/amd64/x86_64/}
BLD_TARGET=		${GARCH}-aux-${LOWER_OPSYS}${OS_VERSION}
OS_LABEL4VERS=		[${OPSYS}${GARCH:M*64:S/amd_//:S/x86_//}]
FULL_GNATGCC=		NOT SET
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/gcc-aux/bin:${PREFIX}/sbin:${PREFIX}/bin

.if ${OPSYS} == DragonFly
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.dragonfly.36A.tar.bz2
.endif

.if ${OPSYS} == FreeBSD
MODERN_BINUTILS=	yes
.  if !empty(OS_VERSION:M[678].*)
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.freebsd.84.tar.bz2
.  else
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.freebsd.100B.tar.bz2
.  endif
.endif

.if ${OPSYS} == "NetBSD"
.if !empty(OS_VERSION:M6.99.*)
   NSUFF=	7.0_DEV
.else
   NSUFF=	${OS_VERSION}
.endif
.if ${GARCH} == i386
   NELF=	elf
.endif
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.netbsd.614.tar.bz2
BLD_TARGET=		${MACHINE_ARCH}-aux-netbsd${NELF}${NSUFF}
.endif

.if ${OPSYS} == "SunOS"
BOOTSTRAP_TRIPLET=	i386-bootstrap-solaris5.11/4.6.1
SOL_OSV=		`expr substr ${OS_VERSION} 3 2`
BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}2.${SOL_OSV}
BOOTSTRAP_COMPILER=	gnat-bootstrap.${MACHINE_ARCH}.solaris.tar.bz2
MODERN_BINUTILS=	yes
.endif

.if defined(MODERN_BINUTILS)
BUILDLINK_DEPMETHOD.binutils=	full
.include "../../devel/binutils/buildlink3.mk"
EXTRA_CONFARGS+=	--with-gnu-ld --with-ld=${PREFIX}/bin/gld
EXTRA_CONFARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas
MY_CONFIGURE_ENV+=	AR=${PREFIX}/bin/gar
MY_CONFIGURE_ENV+=	AS=${PREFIX}/bin/gas
MY_CONFIGURE_ENV+=	LD=${PREFIX}/bin/gld
MY_CONFIGURE_ENV+=	NM=${PREFIX}/bin/gnm
MY_CONFIGURE_ENV+=	RANLIB=${PREFIX}/bin/granlib
.else
EXTRA_CONFARGS+=	--with-gnu-ld --with-ld=/usr/bin/ld
EXTRA_CONFARGS+=	--with-gnu-as --with-as=/usr/bin/as
.endif


# define some important directories and files
WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
NEWBSDIR=		${WRKDIR}/newbs/bootstrap
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE= 		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}/gcc-aux
BSFILENAME=		ada-bootstrap.${GARCH}.${LOWER_OPSYS}.${OS_VERSION:C/[A-Z_.-]//g}.tar


# testing if gcc-aux is already installed - if so, use this compiler along with
# its gnatlink, gnatbind, and gnatmake rather than the older bootstrap versions
.if exists(${LOCALBASE}/gcc-aux/bin/ada)
FULL_GNATGCC=${LOCALBASE}/gcc-aux/bin/ada
.endif


.if ${FULL_GNATGCC} == "NOT SET"
# here we know we need to install the bootstrap compiler
.  if defined(BOOTSTRAP_TRIPLET)
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gnatgcc
.  else
FULL_GNATGCC=${BOOTSTRAP_PREFIX}/bin/gcc
FULL_GNATGXX=${BOOTSTRAP_PREFIX}/bin/g++
.  endif
DISTFILES+= ${BOOTSTRAP_COMPILER}
SITES.${BOOTSTRAP_COMPILER}=	http://downloads.dragonlace.net/src/
FULL_PATH=${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin
.endif


# for port maintenance, invoke "make mdi PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
MASTER_SITES= http://downloads.dragonlace.net/src/ \
   ${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES= \
   ${DISTNAME}.tar.bz2 \
   ada-bootstrap.i386.dragonfly.36A.tar.bz2 \
   ada-bootstrap.i386.freebsd.84.tar.bz2 \
   ada-bootstrap.i386.freebsd.100B.tar.bz2 \
   ada-bootstrap.i386.netbsd.614.tar.bz2 \
   ada-bootstrap.x86_64.dragonfly.36A.tar.bz2 \
   ada-bootstrap.x86_64.freebsd.84.tar.bz2 \
   ada-bootstrap.x86_64.freebsd.100B.tar.bz2 \
   ada-bootstrap.x86_64.netbsd.614.tar.bz2
.endif


# establish ada-aware compiler for use
MY_CONFIGURE_ENV+=	CC=${FULL_GNATGCC}
MY_CONFIGURE_ENV+=	CXX=${FULL_GNATGXX}
MY_CONFIGURE_ENV+=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	LDFLAGS="-lm ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
MY_MAKE_ENV+=		PATH=${FULL_PATH}
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
CONFIGURE_ARGS+=	--enable-threads=posix
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
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/locale/dragonfly
	${MKDIR} ${WRKSRC}/libstdc++-v3/config/os/bsd/dragonfly
	# Apply required composite diff files
.for suffix in ${APPLY_DIFFS}
	@${ECHO} "Applying composite patch diff-${suffix}"
	${PATCH} -d ${WRKSRC} -s -E < ${FILESDIR}/diff-${suffix}
.endfor
	(cd ${WRKSRC}/libstdc++-v3/testsuite && ${PERL5} -i \
	  -pe 's|\*-\*-freebsd\*|*-*-dragonfly* *-*-freebsd*|' ${CXXTS4DF})
	(cd ${WRKSRC}/libstdc++-v3/testsuite/22_locale && ${PERL5} -i \
	  -pe 's|ISO-8859|ISO8859|g;' \
	  -pe 's|ja_JP.eucjp|ja_JP.eucJP|g;' \
	  -pe 's|en_HK|zh_HK|g;' \
	  -pe 's|en_PH|en_NZ|g;' \
	  -pe 's|se_NO|no_NO|g;' \
	  -pe 's|es_MX|es_ES|g;' \
	  -pe 's|ru_RU.UTF8|ru_RU.UTF-8|g' ${LOCALE22FIX})
.if !empty(PKG_OPTIONS:Mstatic) || !empty(PKG_OPTIONS:Mbootstrap)
	# Ensure GNAT tools are built statically
	${PERL5} -pi -e 's/^GCC_LINK_FLAGS=.*/GCC_LINK_FLAGS=-static/' \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.endif
	# Update LINK_SPEC to add gcc-aux lib runpath in every binary
	@${ECHO} "Configuring LINK_SPEC runpath"
	${PERL5} -pi -e 's;\@PREFIX\@;${PREFIX};' \
	  ${WRKSRC}/gcc/config/dragonfly.h \
	  ${WRKSRC}/gcc/config/i386/freebsd.h \
	  ${WRKSRC}/gcc/config/i386/netbsd-elf.h

.if defined(BOOTSTRAP_TRIPLET)
	# Bootstrap compiler has statically linked z, gmp, mpc, mpfr and iconv
	# The only shared lib is libc.so.7, so it should work for a long time.
	# No longer used, only here to support future SunOS bootstrap generation

	${MKDIR} ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../bin ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../lib ${BOOTSTRAP_PREFIX}
	${MV} ${BOOTSTRAP_PREFIX}/../libexec ${BOOTSTRAP_PREFIX}
	${RM} -rf ${BOOTSTRAP_PREFIX}/lib/gcc/${BOOTSTRAP_TRIPLET}/include-fixed
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


.if !empty(PKG_OPTIONS:Mtestsuite) && empty(PKG_OPTIONS:Mbootstrap)
do-test: build test-ada test-fortran test-objc test-cxx test-c

test-ada:
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

test-fortran:
.if !empty(PKG_OPTIONS:Mfortran)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-fortran
.endif

test-objc:
.if !empty(PKG_OPTIONS:Mobjc)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-objc
.endif

test-cxx:
	# libstdc++ always ends with error status, so ignore it
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk \
	check-c++ || ${TRUE}

test-c:
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-c
.endif

do-install:
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} install-strip \
		DESTDIR=${DESTDIR}
	${MV} ${DESTDIR}${PKG_PREFIX}/share ${WRKDIR}/moved_share
.if !empty(PKG_OPTIONS:Mbootstrap)
	${MKDIR} ${NEWBSDIR}
	${CP} -a ${DESTDIR}${PKG_PREFIX}/bin ${NEWBSDIR}/
	${CP} -a ${DESTDIR}${PKG_PREFIX}/lib ${NEWBSDIR}/
	${CP} -a ${DESTDIR}${PKG_PREFIX}/include ${NEWBSDIR}/
	${CP} -a ${DESTDIR}${PKG_PREFIX}/libexec ${NEWBSDIR}/
	${RM} ${NEWBSDIR}/bin/${GARCH}*
	${RM} -rf ${NEWBSDIR}/lib/gcc/${BLD_TARGET}/${GCC_VERSION}/include-fixed
	(cd ${NEWBSDIR}/.. ; \
		${TAR} -cf ${BSFILENAME} bootstrap; ${BZIP2} ${BSFILENAME})
.endif

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
