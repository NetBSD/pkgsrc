# $NetBSD: Makefile,v 1.1.1.1 2011/02/01 20:32:56 drochner Exp $
#

DISTNAME=	gnat-aux-${SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.dragonlace.net/
COMMENT=	GNAT Ada compiler based on GCC ${GCC_BRANCH}
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

SNAPSHOT=	20110125
GCC_BRANCH=     4.6
GCC_POINT=      0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake sed flex bison gm4 perl makeinfo bzip2
USE_BUILTIN.iconv=	no
BUILD_DEPENDS+=		dejagnu>=1.4:../../devel/dejagnu
BUILD_DEPENDS+=		autoconf>=2.6:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

# Requires bootstrap compiler, which is only available for NetBSD i386/AMD64
# and DragonFly i386/AMD64.  Actually bootstrap compilers for OpenBSD and
# FreeBSD also exist, but native packages will be available for those ports.

ONLY_FOR_PLATFORM=	DragonFly-*-*        \
                  	NetBSD-[5-9]*-i386   \
                  	NetBSD-[5-9]*-x86_64

BLD_TARGET=		${MACHINE_ARCH}-aux-${LOWER_OPSYS}${OS_VERSION}
THREAD_MODEL=		posix
OS_LABEL4VERS=		[pkgsrc]
BOOTSTRAP_COMPILER=	NOT_REQUIRED
INTENDED_COMPILER=	NATIVE
BOOTSTRAP_TRIPLET=      NOT SET
FULL_GNATGCC=		NOT SET
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin


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
.endif



# Let's build this without bash
CONFIG_SHELL=		${TOOLS_PATH.sh}


# define some important directories and files
WRKSRC=			${WRKDIR}/build
GCC_WRKSRC=		${WRKDIR}/gcc-${GCC_BRANCH}-${SNAPSHOT}
PKG_PREFIX=		${PREFIX}
CONFIGURE_SCRIPT=	${GCC_WRKSRC}/configure
BOOTSTRAP_PREFIX=	${WRKDIR}/bootstrap
MAN7=			fsf-funding.7 gfdl.7 gpl.7
SINFO=			share/info
SMAN1=			share/man/man1
SMAN7=			share/man/man7
LPATH=			lib/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
LEPATH=			libexec/gcc/${BLD_TARGET}/${GCC_BRANCH}.${GCC_POINT}
REVFILE= 		${GCC_WRKSRC}/gcc/REVISION
LELIST=			cc1 collect2 gnat1 lto1



# testing if gnatgcc, gnatlink, gnatbind and gnatmake are in standard location
# exists function will NOT expand any variable, so it has to be hard-coded
.if exists(/usr/pkg/bin/gnatgcc)
.if exists(/usr/pkg/bin/gnatbind)
.if exists(/usr/pkg/bin/gnatlink)
.if exists(/usr/pkg/bin/gnatmake)
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
#  gnat-bootstrap.x86_64.netbsd.tar.bz2


# establish ada-aware compiler for use
MY_CONFIGURE_ENV=	CC=${FULL_GNATGCC} PATH=${FULL_PATH} CONFIG_SHELL=${CONFIG_SHELL}
MY_MAKE_ENV=		PATH=${FULL_PATH}
MY_MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/gcc


# The standard configuration options
CONFIGURE_ARGS=		--enable-languages=c,ada
CONFIGURE_ARGS+=	--build=${BLD_TARGET}
CONFIGURE_ARGS+=	--program-prefix=gnat
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-gmp=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpfr=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-mpc=${PKG_PREFIX}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PKG_PREFIX}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-threads=${THREAD_MODEL}
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-nls


# The standard make options
MAKE_ARGS=		MAKEINFOFLAGS="--no-split"


# Automatic package list generation
# lib/libquadmath.* will have to be added if __float128 support is added
# Alternatively, libquadmath support could be intentionally disabled.
GENERATE_PLIST=  cd ${PREFIX};
GENERATE_PLIST+= ${FIND} bin/gnat* | ${SORT};
GENERATE_PLIST+= ${FIND} bin/${BLD_TARGET}* | ${SORT};
GENERATE_PLIST+= ${FIND} lib/libiberty.a;
GENERATE_PLIST+= ${FIND} lib/libgcc_s.* \( -type f -or -type l \) | ${SORT};
GENERATE_PLIST+= ${FIND} ${LPATH}/*     \( -type f -or -type l \) | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} ${LEPATH}/*    -type f | ${SORT} -dr;
GENERATE_PLIST+= ${FIND} ${SINFO}/gnat* -type f | ${SORT};
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



do-configure:
	#late switch of compiler to fool default depends checking
	${SETENV} CC=${FULL_GNATGCC}

	#reset timestamps
	cd ${GCC_WRKSRC}; contrib/gcc_update --touch
	${RM} -f ${GCC_WRKSRC}/gcc/*/*.info*
	${TOUCH} ${GCC_WRKSRC}/gcc/cstamp-h.in

	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} ${CONFIG_SHELL} \
	${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}


do-build:
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} all ${MAKE_ARGS}


do-test: build
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} -sk check-ada


do-install:
	cd ${WRKSRC} && ${SETENV} ${MY_MAKE_ENV} ${GMAKE} install
	${STRIP} ${PREFIX}/bin/gnat*
.for k in ${LELIST}
	${STRIP} ${PREFIX}/${LEPATH}/${k}
.endfor



.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
