# $NetBSD: Makefile,v 1.45 2003/10/11 06:24:52 wiz Exp $
#

DISTNAME=		gcc-3.3
PKGREVISION=		5
PKGNAME=		${DISTNAME:S/gcc/gcc3/}
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection, version 3

CONFLICTS+=		gcc-3* pgcc-[0-9]*

NOT_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES

CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
UNLIMIT_RESOURCES=	datasize

FILES_SUBST+=		DISTNAME=${DISTNAME} GCC_PREFIX=${GCC_PREFIX}
MESSAGE_SUBST+=		DISTNAME=${DISTNAME}
PLIST_SUBST+=		DISTNAME=${DISTNAME}

TEXINFO_REQD=		4.2

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		PKG_GCC3_JAVA

INFO_DIR=		${GCC_PREFIX:S|^${PREFIX}/||}/info
INFO_FILES=		cpp.info g77.info gcc.info gccint.info cppinternals.info
.if defined(PKG_GCC3_JAVA)
INFO_FILES+=		fastjar.info gcj.info
.endif

.if ${OPSYS} == "NetBSD" && exists(/usr/include/pthread.h)
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.else
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif
# java takes hours to build, so make it optional
.if !defined(PKG_GCC3_JAVA)
CONFIGURE_ARGS+=	--enable-languages="c,c++,f77,objc,ada"
.endif

.if ${OPSYS} == "NetBSD" && !defined(USE_BINUTILS)
AS_VERSION!=		${AS} --version | ${AWK} '{				\
			    split($$3, v, /[.]/);				\
			    printf "%02d%02d%02d%02d\n",v[1],v[2],v[3],v[4];	\
			    exit;						\
			}'
USE_BINUTILS!=		${TEST} ${AS_VERSION} -lt 02130201 && echo YES || echo NO
.endif

.if defined(USE_BINUTILS) && ${USE_BINUTILS} == "YES"
DEPENDS=		binutils>=2.13.2.1:../../devel/binutils
CONFIGURE_ARGS+=	--with-as=${PREFIX}/${MACHINE_GNU_PLATFORM}/bin/as
#.  include "../../devel/binutils/buildlink2.mk"
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-shared
.else
.  if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-shared
.  else
CONFIGURE_ARGS+=	--disable-shared
.  endif
.  if ${CC:M*gcc*} == ""
ALL_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/${DISTNAME}
GCC_VERSION=	${PKGVERSION:C|nb.*||}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${GCC_VERSION}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/gcc_update --touch

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

post-install:
.if ${OPSYS} == "SunOS"
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${DISTNAME}
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${PREFIX}/share/examples/${DISTNAME}/mk.conf
	${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc
#	${LN} -f ${GCC_PREFIX}/bin/g77 ${GCC_PREFIX}/bin/f77
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
CONFIGURE_ENV+=	LDFLAGS="${_STRIPFLAG_CC}"
MAKE_ENV+=	GCC_PREFIX="${GCC_PREFIX}"

# On NetBSD, the gcc-2.95.3 for:
#
#     alpha
#
# have an optimization bug when compiling with -O2 that is tickled by:
#
#   java/parse.o
#
# note that we don't override CFLAGS and CPPFLAGS because we want the
# crosscompiled compiler to be build with optimization.  This only
# disables optimization for the stage 1 build.
#
.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "alpha"
CONFIG_CFLAGS=	${CFLAGS:C/-O[0-9]*//g}
CONFIG_CPPFLAGS=	${CPPFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+=	CFLAGS="${CONFIG_CFLAGS}" CPPFLAGS="${CONFIG_CPPFLAGS}"
.  endif
.endif
