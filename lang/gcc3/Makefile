# $NetBSD: Makefile,v 1.9 2003/04/14 04:30:21 salo Exp $
#

DISTNAME=		gcc-3.2.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

CONFLICTS+=		pgcc-[0-9]*

NOT_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}

FILES_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV} GCC_PREFIX=${GCC_PREFIX}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}

TEXINFO_REQD=		4.1

INFO_FILES=		cpp.info g77.info gcc.info gcj.info

.include "../../mk/bsd.prefs.mk"

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

GCC_PREFIX=		${PREFIX}/${PKGNAME_NOREV}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	${TOUCH} ${TOUCH_FLAGS}	${WRKSRC}/gcc/c-gperf.h
	${ECHO} "bogus" > ${WRKSRC}/gcc/cstamp-h.in

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${PREFIX}/etc/${PKGNAME_NOREV}.mk
	${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc
#	${LN} -f ${GCC_PREFIX}/bin/g77 ${GCC_PREFIX}/bin/f77
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}

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
