# $NetBSD: Makefile,v 1.50 2009/06/14 22:58:01 joerg Exp $

DISTNAME=		gcc-2.95.3
PKGNAME=		gcc-ssp-2.95.3.13
PKGREVISION=		4
CATEGORIES=		lang security
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.trl.ibm.com/projects/security/ssp/
COMMENT=		GNU Compiler Collection with Stack-smashing protection

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

SSP_PATCH=		protector-2.95.3-13.tar.gz
DISTFILES+=		${DISTNAME}.tar.gz ${SSP_PATCH}
SITES.protector-2.95.3-13.tar.gz=	http://www.trl.ibm.com/projects/security/ssp/gcc2_95_3/

PATCHDIR=		${.CURDIR}/../gcc/patches
GCC_FILESDIR=		${.CURDIR}/../gcc/files

#ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc
#
# Build error for NetBSD/alpha
#NOT_FOR_PLATFORM=	NetBSD-*-alpha \
#			NetBSD-*-powerpc NetBSD-*-macppc \
#			NetBSD-*-prep NetBSD-*-bebox NetBSD-*-ofppc \
#			NetBSD-*-amigappc NetBSD-*-sandpoint
NOT_FOR_PLATFORM=	Interix-*-* *-*-x86_64 DragonFly-*-*

USE_TOOLS+=		gmake

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-shared

USE_TOOLS+=		chmod pax
MAKE_ENV+=		ac_cv_prog_chmod=${TOOLS_CHMOD:Q}
MAKE_ENV+=		SHELL=${CONFIG_SHELL}

CONFIGURE_DIRS=		${WRKDIR}/objdir
BUILD_DIRS=		${CONFIGURE_DIRS}

FILES_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}		\
			GCC_PREFIX=${GCC_PREFIX:Q}
PLIST_SUBST+=		GCC_PREFIX=${GCC_PREFIX:S|^${PREFIX}/||:Q}
MESSAGE_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV}

INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
.  if ${CC:M*gcc*} == ""
BUILD_TARGET=		bootstrap
.  endif
# we know it's a GNU toolchain on Linux and the BSDs.
.elif ${OPSYS:M*BSD} != "" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
.else
# play it safe, force a bootstrap build if we don't know for sure it
# is gcc.
.  if ${CC:M*gcc*} == ""
BUILD_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/${PKGNAME_NOREV}
GCC_VERSION=	${DISTNAME:C/^.*-//}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${GCC_VERSION}
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${GCC_FILESDIR}/xm-netbsd.h ${WRKSRC}/gcc/config
	${CP} ${GCC_FILESDIR}/xm-target64.h ${WRKSRC}/gcc/config
	for file in ${GCC_FILESDIR}/*_* ; do \
		arch=`${BASENAME} $${file} | ${SED} -e "s/_.*//"`;	\
		dest=`${BASENAME} $${file} | ${SED} -e "s/$${arch}_//"`; \
		${MKDIR} ${WRKSRC}/gcc/config/$${arch};			\
		${CP} $${file} ${WRKSRC}/gcc/config/$${arch}/$${dest};	\
	done; \
	${RM} ${WRKSRC}/gcc/config/alpha/netbsd-elf.h
	${RM} ${WRKSRC}/gcc/config/arm/t-netbsd
	${RM} ${WRKSRC}/gcc/config/mips/x-netbsd
	${RM} ${WRKSRC}/libf2c/libF77/dtime_.c
	${RM} ${WRKSRC}/libf2c/libF77/etime_.c

post-patch:
	cd ${WRKDIR} && pax -O -zrf ${_DISTDIR}/${SSP_PATCH}
	${CP} ${WRKDIR}/protector.c ${WRKDIR}/protector.h ${WRKSRC}/gcc/
	${PATCH} -p0 -d ${WRKSRC} --forward --quiet -E < ${WRKDIR}/protector.dif
	${PATCH} -p0 -d ${WRKSRC} --forward --quiet -E < ${WRKDIR}/protectonly.dif

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/egcs_update --touch

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc.mk > ${WRKDIR}/gcc.mk
.if ${OPSYS} != "SunOS"
	@${ECHO} "===> Check whether stack protection works or not"
	${BUILD_DIRS}/gcc/xgcc -B${BUILD_DIRS}/gcc/ -O2 -o ${WRKDIR}/buffer ${FILESDIR}/buffer.c
	ulimit -c 0 && ${WRKDIR}/buffer abcdefghijklmnopqrstuvwxyz  2> ${WRKDIR}/output || ${TRUE}
	@if [ x"`${CAT} ${WRKDIR}/output`" = "x: stack smashing attack in function main" ]; then \
	    ${ECHO} "===> Stack protection succeeded."; \
	    exit 0; \
	else \
	    ${ECHO} "**** Stack protection failed."; \
	    exit 1; \
	fi
.endif

.if ${OPSYS} == "SunOS"
#
# remove empty file and directories that show up when one does:
#       make install; make deinstall; make install
#
post-install:
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.else
post-install:
.  if exists(/usr/include/g++/FlexLexer.h)
	${LN} -fs /usr/include/g++/FlexLexer.h				\
		${GCC_PREFIX}/include/g++-3/FlexLexer.h
.  endif
	 ${RM} -f ${GCC_ARCHDIR}/include/curses.h ${GCC_PREFIX}/bin/cc
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGNAME_NOREV}
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/share/examples/${PKGNAME_NOREV}/mk.conf
	${LN} -s gcc ${GCC_PREFIX}/bin/cc
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
