# $NetBSD: Makefile,v 1.15 2001/11/01 09:41:13 jlam Exp $

DISTNAME=		gcc-2.95.2
PKGNAME=		pgcc-2.95.2.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

PATCH_SITES=		http://goof.com/pcg/data/source/
PATCHFILES=		gcc-${PGCC_VERSION}-${PKGNAME}.diff.gz
PATCH_DIST_ARGS=	-d ${SRCDIR} -s -p1 -E

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://goof.com/pcg/
COMMENT=		Pentium GNU Compiler Collection

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

# 'Pentium GCC' is optimized for the Intel Pentium processor, but should
# work on all platforms on which GCC works.
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-sparc SunOS-*-*

.include "../../mk/bsd.prefs.mk"

FILESDIR=		${.CURDIR}/../../lang/gcc/files
PATCHDIR=		${.CURDIR}/../../lang/gcc/patches
PKGDIR=			${.CURDIR}/../../lang/gcc

DESCR_SRC=		${.CURDIR}/DESCR

.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}elf
.else
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GCC_PLATFORM} \
			--prefix=${GCC_PREFIX} \
			--enable-shared
CONFIGURE_SCRIPT=	${SRCDIR}/configure
INFO_FILES=		chill.info cpp.info g77.info gcc.info

# For pgcc, GCC_VERSION is actually the name of a subdirectory in the gcc
# library tree.  We keep the odd name to keep this Makefile in-sync with
# lang/gcc/Makefile.  PGCC_VERSION is set to the actual version of pgcc.
#
PGCC_VERSION=		${PKGNAME:C/.*-//}
GCC_VERSION=		${PKGNAME}
MESSAGE_SUBST+=		MAKE=${MAKE}
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION} \
			MACHINE_GCC_PLATFORM=${MACHINE_GCC_PLATFORM}
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != SunOS)
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld --infodir=${PREFIX}/info

GCC_PREFIX=		${LOCALBASE}/${PKGNAME}
.if ${MACHINE_PLATFORM:MNetBSD-*-sparc}
PLIST_SRC=		${PKGDIR}/PLIST.NetBSD-sparc
PLIST_SRC+=		${PKGDIR}/PLIST
.endif
.else
.if (${CC} != gcc)
ALL_TARGET=		bootstrap
.endif
GCC_PREFIX=		${LOCALBASE}
PLIST_SRC=		${PKGDIR}/PLIST.SunOS
MESSAGE=		${PKGDIR}/MESSAGE.SunOS
CONFLICTS+=		gcc-[0-9]* pgcc-[0-9]*
.endif

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/netbsd*.ml ${WRKSRC}/../${DISTNAME}/libstdc++/config

post-patch:
	${ECHO} "bogus" >${WRKSRC}/../${DISTNAME}/gcc/cstamp-h.in

.if (${OPSYS} != SunOS)
post-build:
	for FILE in ${FILESDIR}/gcc.mk; do \
	  ${SED} -e 's#@@MAKE@@#${MAKE}#g' \
		 -e 's#@@PKGNAME@@#${PKGNAME}#g' \
		 -e 's#@@PREFIX@@#${PREFIX}#g' \
	   <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done
.endif

.if (${OPSYS} != SunOS)
post-install:
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h ${PREFIX}/${PKGNAME}/bin/cc
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
.endif

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${STRIPFLAG}
