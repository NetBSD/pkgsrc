# $NetBSD: Makefile,v 1.1 2001/05/22 13:54:34 kent Exp $

DISTNAME=		gcc-2.95.2
PKGNAME=		gcc-ssp-2.95.2
CATEGORIES=		lang security
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		kent@netbsd.org
HOMEPAGE=		http://www.trl.ibm.com/projects/security/ssp/
COMMENT=		GNU Compiler Collection with Stack-smashing protection

MASTER_SITES+=		http://www.trl.ibm.com/projects/security/ssp/gcc2_95_2/
SSP_PATCH=		protector2-95-2.tar.gz
DISTFILES+=		${DISTNAME}.tar.gz ${SSP_PATCH}
PATCHDIR=		../gcc/patches
GCC_FILESDIR=		../gcc/files

BUILD_DEPENDS+=		bison-*:../../devel/bison

# The platforms listed below are the only tested platforms so far.
# If you get gcc working on other platforms, then please add them.
ONLY_FOR_PLATFORM=	NetBSD-*-i386

.include "../../mk/bsd.prefs.mk"

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

GCC_VERSION=		${PKGNAME:C/.*-//}
MESSAGE_SUBST+=		MAKE=${MAKE}
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION} \
			MACHINE_GCC_PLATFORM=${MACHINE_GCC_PLATFORM}
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != SunOS)
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
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
	${CP} ${GCC_FILESDIR}/netbsd*.ml ${WRKSRC}/../${DISTNAME}/libstdc++/config

post-patch:
	${ECHO} "bogus" >${WRKSRC}/../${DISTNAME}/gcc/cstamp-h.in
	cd ${WRKDIR} && /usr/bin/tar zxf ${_DISTDIR}/${SSP_PATCH}
	${CP} ${WRKDIR}/protector.c ${WRKDIR}/protector.h ${WRKDIR}/${DISTNAME}/gcc/
	${PATCH} -d ${WRKDIR}/${DISTNAME}/gcc --forward --quiet -E < ${WRKDIR}/protector.dif

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
