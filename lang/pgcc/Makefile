# $NetBSD: Makefile,v 1.1.1.1 2001/02/20 23:39:18 jlam Exp $

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

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

# 'Pentium GCC' is optimized for the Intel Pentium processor, but should
# work on all platforms on which GCC works.
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			SunOS-*-*

.include "../../mk/bsd.prefs.mk"

FILESDIR=		${PKGSRCDIR}/lang/gcc/files
PATCHDIR=		${PKGSRCDIR}/lang/gcc/patches
PKGDIR=			${PKGSRCDIR}/lang/gcc/pkg

MD5_FILE=		${.CURDIR}/files/md5
DESCR_SRC=		${.CURDIR}/pkg/DESCR

.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}elf
.else
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GCC_PLATFORM} \
			--prefix=${GCC_PREFIX}
CONFIGURE_SCRIPT=	${SRCDIR}/configure

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
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
GCC_PREFIX=		${LOCALBASE}/${PKGNAME}
.else
.if (${CC} != gcc)
ALL_TARGET=		bootstrap
.endif
GCC_PREFIX=		${LOCALBASE}
PLIST_SRC=		${PKGDIR}/PLIST.SunOS
MESSAGE=		${PKGDIR}/MESSAGE.SunOS
.endif

post-extract:
	${MKDIR} ${WRKSRC}

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
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
.endif

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${STRIPFLAG}
