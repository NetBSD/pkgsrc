# $NetBSD: Makefile,v 1.9 2001/01/11 06:53:10 tron Exp $

DISTNAME=		gcc-2.95.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

# NetBSD-arm32, NetBSD-i386 and NetBSD-m68k are the only tested platforms
# so far. If you got it working on other platforms please add them.
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			SunOS-*-*

.include "../../mk/bsd.prefs.mk"

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

GCC_VERSION=		${PKGNAME:C/.*-//}
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION} \
			MACHINE_GCC_PLATFORM=${MACHINE_GCC_PLATFORM}
SRCDIR=			${WRKDIR}/${PKGNAME}
WRKSRC=			${WRKDIR}/objdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != SunOS)
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
GCC_PREFIX=		${LOCALBASE}/${PKGNAME}
MESSAGE_FILE=		${WRKDIR}/MESSAGE
.else
.if (${CC} != gcc)
ALL_TARGET=		bootstrap
.endif
GCC_PREFIX=		${LOCALBASE}
PLIST_SRC=		${PKGDIR}/PLIST.SunOS
MESSAGE_FILE=		${PKGDIR}/MESSAGE.SunOS
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${ECHO} "bogus" >${WRKSRC}/../${DISTNAME}/gcc/cstamp-h.in

.if (${OPSYS} != SunOS)
post-build:
	for FILE in ${FILESDIR}/gcc.mk ${PKGDIR}/MESSAGE; do \
	  ${SED} -e 's#@@MAKE@@#${MAKE}#g' \
		 -e 's#@@PKGNAME@@#${PKGNAME}#g' \
		 -e 's#@@PREFIX@@#${PREFIX}#g' \
	   <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done
.endif

post-install:
	${RM} -f ${PREFIX}/${PKGNAME}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h ${PREFIX}/${PKGNAME}/bin/cc
.if (${OPSYS} != SunOS)
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
.endif

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${STRIPFLAG}
