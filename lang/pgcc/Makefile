# $NetBSD: Makefile,v 1.24 2004/01/24 13:51:15 grant Exp $

DISTNAME=		gcc-2.95.2
PKGNAME=		pgcc-2.95.2.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

PATCH_SITES=		http://goof.com/pcg/data/source/
PATCHFILES=		gcc-${PGCC_VERSION}-${PKGNAME_NOREV}.diff.gz
PATCH_DIST_STRIP+=	-p1

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://goof.com/pcg/
COMMENT=		Pentium GNU Compiler Collection

# 'Pentium GCC' is optimized for the Intel Pentium processor, but should
# work on all platforms on which GCC works.
ONLY_FOR_PLATFORM=	NetBSD-*-arm NetBSD-*-arm32 NetBSD-*-i386	\
			NetBSD-*-m68k NetBSD-*-sparc SunOS-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-shared

CONFIGURE_DIRS=		${WRKDIR}/objdir
BUILD_DIRS=		${CONFIGURE_DIRS}

INFO_DIR=		${GCC_PREFIX:S|^${PREFIX}/||}/info
INFO_FILES=		chill.info cpp.info g77.info gcc.info

# For pgcc, GCC_VERSION is actually the name of a subdirectory in the gcc
# library tree.  We keep the odd name to keep this Makefile in-sync with
# lang/gcc/Makefile.  PGCC_VERSION is set to the actual version of pgcc.
#
PGCC_VERSION=	${PKGNAME:C/.*-//:C/nb[0-9]*$//}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${GCC_VERSION}
GCC_VERSION=	${PKGNAME}

.include "../../mk/bsd.prefs.mk"

GCC_PREFIX=		${PREFIX}/${PKGNAME_NOREV}
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if ${OPSYS} == "SunOS"
.  if ${CC:M*gcc*} == ""
ALL_TARGET=		bootstrap
.  endif
# we know it's a GNU toolchain on Linux and the BSDs.
.elif ${OPSYS:M*BSD} != "" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
.else
# play it safe, force a bootstrap build if we don't know for sure it
# is gcc.
.  if ${CC:M*gcc*} == ""
ALL_TARGET=             bootstrap
.  endif
.endif

FILES_SUBST+=		GCC_PREFIX=${GCC_PREFIX}
FILES_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}

post-extract:
	${CP} ${FILESDIR}/netbsd*.ml ${WRKSRC}/libstdc++/config

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/egcs_update --touch

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc.mk > ${WRKDIR}/gcc.mk

post-install:
.if (${OPSYS} == "SunOS")
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.else
	${RM} -f ${GCC_ARCHDIR}/include/curses.h ${GCC_PREFIX}/bin/cc
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/share/examples/${PKGNAME_NOREV}/mk.conf
	${LN} -s gcc ${GCC_PREFIX}/bin/cc
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
