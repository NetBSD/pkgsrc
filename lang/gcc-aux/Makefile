# $NetBSD: Makefile,v 1.40 2022/06/28 11:34:10 wiz Exp $

PKGNAME=	gcc-aux-${SNAPSHOT}
PKGREVISION=	7
DISTNAME=	gcc-${GCC_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	${DISTNAME}.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

LANGS=		c ada c++
USE_TOOLS+=	gmake sed:run perl makeinfo bzip2 patch pod2man tar
APPLY_DIFFS=	core ada cxx

RELRO_SUPPORTED=	no
MKPIE_SUPPORTED=	no

.include "Makefile.version"
.include "Makefile.testsuite"
.include "../../mk/bsd.prefs.mk"
.include "options.mk"

CHECK_PORTABILITY_SKIP+=	contrib/* # not needed

# Requires bootstrap compiler, which is only available for on selected systems
# Disable SunOS for now until multilib version can be built and tested.

ONLY_FOR_PLATFORM=	DragonFly-*-x86_64   \
			FreeBSD-*-i386       \
			FreeBSD-*-x86_64     \
			NetBSD-*-i386   \
			NetBSD-*-x86_64 \
			SunOS-5.1[1-9]*-i386 \
			SunOS-5.1[1-9]*-x86_64

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

.if ${OPSYS} == NetBSD
.  if !empty(OS_VERSION:M6.99.*)
NSUFF=			7.0_DEV
.  elif !empty(OS_VERSION:M7.99.*)
NSUFF=			8.0_DEV
.  else
NSUFF=			${OS_VERSION}
.  endif
.  if ${GARCH} == i386
NELF=			elf
.  endif
XLDF=			-lm
.  if ${OS_VERSION:R} < 7
MODERN_BINUTILS=	yes
.  endif
BOOTSTRAP_COMPILER=	ada-bootstrap.${GARCH}.netbsd.614.tar.bz2
BLD_TARGET=		${MACHINE_ARCH}-aux-netbsd${NELF}${NSUFF}
.  if ${OS_VERSION:R} == 5
CORRECTIONS=		g-socthi-bsd.adb
CRXN=			C5
.  else
CORRECTIONS=		g-socthi-bsd.adb g-socthi.ads \
			s-osinte-netbsd.ads s-osprim-posix.adb
CRXN=			C6
.  endif
C5_g-socthi-bsd.adb=	Syscall_Socket/__socket30
C6_g-socthi-bsd.adb=	Syscall_Socket/__socket30
C6_g-socthi.ads=	C_Select/__select50
C6_s-osinte-netbsd.ads=	nanosleep/__nanosleep50 \
			clock_getres/__clock_getres50 \
			clock_gettime/__clock_gettime50
C6_s-osprim-posix.adb=	nanosleep/__nanosleep50 \
			gettimeofday/__gettimeofday50
.endif

.if ${OPSYS} == SunOS
SOL_OSV!=		expr substr ${OS_VERSION} 3 2
BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}2.${SOL_OSV}
BOOTSTRAP_COMPILER=	ada-bootstrap.x86_64.solaris.511.tar.bz2
.  if ${ABI} == 64
EXTRA_CONFARGS+=	--enable-multilib
.  else
COMPILER_ABI_SWITCH=	-m32
.  endif
MY_CONFIGURE_ENV+=	OBJDUMP=${PREFIX}/bin/gobjdump
MODERN_BINUTILS=	yes
NATIVE_LINKER!=		which ld
.endif

.if defined(MODERN_BINUTILS)
BUILDLINK_DEPMETHOD.binutils=	full
.include "../../devel/binutils/buildlink3.mk"
EXTRA_CONFARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas
MY_CONFIGURE_ENV+=	AR=${PREFIX}/bin/gar
MY_CONFIGURE_ENV+=	AS=${PREFIX}/bin/gas
MY_CONFIGURE_ENV+=	NM=${PREFIX}/bin/gnm
MY_CONFIGURE_ENV+=	RANLIB=${PREFIX}/bin/granlib
.  if defined(NATIVE_LINKER)
EXTRA_CONFARGS+=	--without-gnu-ld --with-ld=${NATIVE_LINKER}
.  else
EXTRA_CONFARGS+=	--with-gnu-ld --with-ld=${PREFIX}/bin/gld.gold
MY_CONFIGURE_ENV+=	LD=${PREFIX}/bin/gld.gold
.  endif
.else
EXTRA_CONFARGS+=	--with-gnu-ld --with-ld=/usr/bin/ld
EXTRA_CONFARGS+=	--with-gnu-as --with-as=/usr/bin/as
.endif


# define some important directories and files
WRKSRC=			${WRKDIR}/gcc-${GCC_VERSION}
BUILDDIR=		${WRKDIR}/build
NEWBSDIR=		${WRKDIR}/newbs/bootstrap
SYSLIBDIR=		${WRKDIR}/lib
CFG_SCRIPT=		${WRKSRC}/configure
REVFILE=		${WRKSRC}/gcc/REVISION
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
PKG_PREFIX=		${PREFIX}/gcc-aux
BSFILENAME=		ada-bootstrap.${GARCH}.${LOWER_OPSYS}.${OS_VERSION:C/[A-Z_.-]//g}.tar


# testing if gcc-aux is already installed - if so, use this compiler along with
# its gnatlink, gnatbind, and gnatmake rather than the older bootstrap versions
.if exists(${LOCALBASE}/gcc-aux/bin/ada)
FULL_GNATGCC=	${LOCALBASE}/gcc-aux/bin/ada
FULL_GNATGXX=	${LOCALBASE}/gcc-aux/bin/g++
.endif


.if ${FULL_GNATGCC} == "NOT SET"
# here we know we need to install the bootstrap compiler
.  if defined(BOOTSTRAP_TRIPLET)
FULL_GNATGCC=	${BOOTSTRAP_PREFIX}/bin/gnatgcc
.  else
FULL_GNATGCC=	${BOOTSTRAP_PREFIX}/bin/gcc ${COMPILER_ABI_SWITCH}
FULL_GNATGXX=	${BOOTSTRAP_PREFIX}/bin/g++ ${COMPILER_ABI_SWITCH}
.  endif
DISTFILES+=	${BOOTSTRAP_COMPILER}
SITES.${BOOTSTRAP_COMPILER}=	http://downloads.dragonlace.net/src/
FULL_PATH=	${BOOTSTRAP_PREFIX}/bin:/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin
.endif


# for port maintenance, invoke "make mdi PLUS_BOOTSTRAPS=1"
.if defined(PLUS_BOOTSTRAPS)
MASTER_SITES=	http://downloads.dragonlace.net/src/
MASTER_SITES+=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_VERSION}/}
DISTFILES=	\
	${DISTNAME}.tar.bz2 \
	ada-bootstrap.i386.dragonfly.36A.tar.bz2 \
	ada-bootstrap.i386.freebsd.84.tar.bz2 \
	ada-bootstrap.i386.freebsd.100B.tar.bz2 \
	ada-bootstrap.i386.netbsd.614.tar.bz2 \
	ada-bootstrap.x86_64.dragonfly.36A.tar.bz2 \
	ada-bootstrap.x86_64.freebsd.84.tar.bz2 \
	ada-bootstrap.x86_64.freebsd.100B.tar.bz2 \
	ada-bootstrap.x86_64.netbsd.614.tar.bz2 \
	ada-bootstrap.x86_64.solaris.511.tar.bz2
.endif

# establish ada-aware compiler for use
MY_CONFIGURE_ENV+=	CC=${FULL_GNATGCC:Q}
MY_CONFIGURE_ENV+=	CXX=${FULL_GNATGXX:Q}
MY_CONFIGURE_ENV+=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	LDFLAGS="${XLDF} ${COMPILER_RPATH_FLAG}${PREFIX}/lib"
MY_MAKE_ENV+=		PATH=${FULL_PATH}
MY_MAKE_ENV+=		LD_LIBRARY_PATH=${BUILDDIR}/gcc${EXTRA_LLP}
# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MY_MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MY_MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}


# The standard configuration options
CONFIGURE_ARGS=		--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--prefix=${PKG_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--enable-checking=release
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-libcilkrts
CONFIGURE_ARGS+=	--disable-libitm
CONFIGURE_ARGS+=	${EXTRA_CONFARGS}

# Automatic package list generation
GENERATE_PLIST=		cd ${DESTDIR}${PREFIX};
GENERATE_PLIST+=	${FIND} * \( -type f -or -type l \) | ${SORT} -dr;


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
.if ${OPSYS} == NetBSD
.  for sysfile in ${CORRECTIONS}
.    for pair in ${${CRXN}_${sysfile}}
	${PERL5} -pi -e 's|C, ${pair:H}, ".*"|C, ${pair:H}, "${pair:T}"|' \
		${WRKSRC}/gcc/ada/${sysfile}
.    endfor
.  endfor
.  if ${CRXN} == C5
	${PERL5} -pi -e 's|new int64_t|new int|' \
		${WRKSRC}/gcc/ada/s-osinte-netbsd.ads
	${PERL5} -pi -e 's|new Long_Integer|new Integer|' \
		${WRKSRC}/gcc/ada/s-osprim-posix.adb
.  endif
	# GCC < 9's fixincludes is broken for NetBSD >= 9.0 (PR pkg/54362)
	# This affects the bootstrap GCC used, too.
	# Fixed in https://github.com/gcc-mirror/gcc/commit/c7af124dca795b835d7fda24192b9e4849f1bb08
	${FIND} ${WRKDIR} -name stddef.h -exec ${SED} -i -e 's|defined(_ANSI_H_)|1|' {} \;
.endif
.if defined(STATIC_BUILD) || !empty(PKG_OPTIONS:Mbootstrap)
.  if ${OPSYS} != SunOS
	# Ensure GNAT tools are built statically
	${PERL5} -pi -e 's/^GCC_LINK_FLAGS=.*/GCC_LINK_FLAGS=-static/' \
	  ${WRKSRC}/gcc/ada/gcc-interface/Makefile.in
.  endif
.endif
.if !exists(${LOCALBASE}/gcc-aux/bin/ada) && ${OPSYS} == SunOS
	# In case /usr/pkg/bin/gas doesn't exist, establish fallback
	${LN} -s ${PREFIX}/bin/gas ${BOOTSTRAP_PREFIX}/bin/as
.endif
	# Illumos /usr/ccs binaries are symlinked to /usr/bin
	# elfdump was present on OmniOS but not in Joyent dev area
	${PERL5} -i -pe 's|/usr/ccs/bin|/usr/bin|g;' \
	  -pe 's|readelf -s|greadelf -s|' ${WRKSRC}/contrib/make_sunver.pl
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
.  if (${OPSYS} == NetBSD) && (${MACHINE_ARCH} == x86_64)
	# NetBSD has an extremely small default stacksize of 2MB, which is
	# insufficient for the gnat.dg testsuite.
	# specifically: entry_queues test on AMD64
	# Unlimiting stack resources on i386-netbsdelf* will result in
	# failure of gnat.dg/task_stack_align.adb execution test.
	cd ${BUILDDIR} && \
	${ULIMIT_CMD_stacksize} && \
	${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada
.  else
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} DEJAGNU_TIMEOUT=30 \
		${GMAKE} -sk check-ada
.  endif

test-fortran:
.  if !empty(PKG_OPTIONS:Mfortran)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-fortran
.  endif

test-objc:
.  if !empty(PKG_OPTIONS:Mobjc)
	cd ${BUILDDIR} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-objc
.  endif

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
create-bootstrap: stage-install
	${MKDIR} ${NEWBSDIR}
	${CP} -RpP ${DESTDIR}${PKG_PREFIX}/bin ${NEWBSDIR}/
	${CP} -RpP ${DESTDIR}${PKG_PREFIX}/lib ${NEWBSDIR}/
	${CP} -RpP ${DESTDIR}${PKG_PREFIX}/include ${NEWBSDIR}/
	${CP} -RpP ${DESTDIR}${PKG_PREFIX}/libexec ${NEWBSDIR}/
	${RM} ${NEWBSDIR}/bin/${GARCH}*
	${RM} -rf ${NEWBSDIR}/lib/gcc/${BLD_TARGET}/${GCC_VERSION}/include-fixed
	(cd ${NEWBSDIR}/.. ; \
		${TAR} -cf ${BSFILENAME} bootstrap; ${BZIP2} ${BSFILENAME})
.endif

.include "../../mk/bsd.pkg.mk"
