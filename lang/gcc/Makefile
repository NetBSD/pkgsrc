# $NetBSD: Makefile,v 1.5 2000/09/16 00:19:45 tron Exp $

DISTNAME=		gcc-2.95.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html

BUILD_DEPENDS+=		${LOCALBASE}/bin/bison:../../devel/bison

# NetBSD-arm32 and NetBSD-i386 are the only tested platform so far.
# If you got it working on other platforms please add them.
ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}elf
.else
MACHINE_GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GCC_PLATFORM} \
			--prefix=${LOCALBASE}/${PKGNAME} \
			--with-gnu-as --with-gnu-ld
CONFIGURE_SCRIPT=	${SRCDIR}/configure

GCC_VERSION=		${PKGNAME:C/.*-//}
MESSAGE_FILE=		${WRKDIR}/MESSAGE
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION} \
			MACHINE_GCC_PLATFORM=${MACHINE_GCC_PLATFORM}
SRCDIR=			${WRKDIR}/${PKGNAME}
WRKSRC=			${WRKDIR}/objdir

post-extract:
	${MKDIR} ${WRKSRC}

post-build:
	for FILE in ${FILESDIR}/gcc.mk ${PKGDIR}/MESSAGE; do \
	  ${SED} -e 's#@@MAKE@@#${MAKE}#g' \
		 -e 's#@@PKGNAME@@#${PKGNAME}#g' \
		 -e 's#@@PREFIX@@#${PREFIX}#g' \
	   <$$FILE >${WRKDIR}/$${FILE##*/}; \
	done

post-install:
	${RM} -f ${PREFIX}/${PKGNAME}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h ${PREFIX}/${PKGNAME}/bin/cc
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk

.include "../../mk/bsd.pkg.mk"
