# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:39 hubertf Exp $

DISTNAME=		gcc-2.95.2
GCC_VERSION=		2.95.2
PKGNAME=		gcc-ssp-2.95.2
PKGREVISION=		3
PKGBASENAME=		gcc-ssp
CATEGORIES=		lang security
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		kent@netbsd.org
HOMEPAGE=		http://www.trl.ibm.com/projects/security/ssp/
COMMENT=		GNU Compiler Collection with Stack-smashing protection

MASTER_SITES+=		http://www.trl.ibm.com/projects/security/ssp/gcc2_95_2/
SSP_PATCH=		protector-2.95.2-2.tar.gz
DISTFILES+=		${DISTNAME}.tar.gz ${SSP_PATCH}
PATCHDIR=		../gcc/patches
GCC_FILESDIR=		../gcc/files

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

# Please let me know what platforms this package works or doesn't work on.
#ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc
#
# Build error for NetBSD/alpha
NOT_FOR_PLATFORM=	NetBSD-*-alpha


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

MESSAGE_SUBST+=		MAKE=${MAKE} \
			PKGBASENAME=${PKGBASENAME}
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION} \
			MACHINE_GCC_PLATFORM=${MACHINE_GCC_PLATFORM} \
			PKGBASENAME=${PKGBASENAME}
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != SunOS)
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld
GCC_PREFIX=		${LOCALBASE}/${PKGBASENAME}
.if ${MACHINE_PLATFORM:MNetBSD-*-sparc}
PLIST_SRC=		${PKGDIR}/PLIST.NetBSD-sparc
PLIST_SRC+=		${PKGDIR}/PLIST
.endif
.else
ALL_TARGET=		bootstrap
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
	${PATCH} -d ${WRKDIR}/${DISTNAME} --forward --quiet -E < ${WRKDIR}/protector.dif
	${PATCH} -d ${WRKDIR}/${DISTNAME} --forward --quiet -E < ${WRKDIR}/protectonly.dif

.if (${OPSYS} != SunOS)
post-build:
	for FILE in ${FILESDIR}/gcc.mk; do \
	  ${SED} -e 's#@@MAKE@@#${MAKE}#g' \
		 -e 's#@@PKGBASENAME@@#${PKGBASENAME}#g' \
		 -e 's#@@PREFIX@@#${PREFIX}#g' \
	   <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done
	${WRKSRC}/gcc/xgcc -B${WRKSRC}/gcc/ -O2 -o ${WRKDIR}/buffer ${FILESDIR}/buffer.c
	ulimit -c 0 && ${WRKDIR}/buffer abcdefghijklmnopqrstuvwxyz  2> ${WRKDIR}/output || true
	@if [ x"`cat ${WRKDIR}/output`" = "x: stack smashing attack in function main" ]; then \
	    echo "---- Stack protection succeeded."; \
	    exit 0; \
	else \
	    echo "*** Stack protection failed."; \
	    exit 1; \
	fi
.endif

.if (${OPSYS} != SunOS)
post-install:
	${LN} -s gcc ${PREFIX}/${PKGBASENAME}/bin/cc
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GCC_PLATFORM}/${GCC_VERSION}/include/curses.h
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGBASENAME}.mk
.endif

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${STRIPFLAG}
