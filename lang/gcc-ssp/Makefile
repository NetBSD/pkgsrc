# $NetBSD: Makefile,v 1.13 2002/07/13 10:08:49 kent Exp $

DISTNAME=		gcc-2.95.3
GCC_VERSION=		2.95.3
PKGNAME=		gcc-ssp-2.95.3.5
PKGVERSION=		${GCC_VERSION}
PKGREVISION=
PKGBASENAME=		gcc-ssp
CATEGORIES=		lang security
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.trl.ibm.com/projects/security/ssp/
COMMENT=		GNU Compiler Collection with Stack-smashing protection

SSP_PATCH=		protector-2.95.3-5.tar.gz
DISTFILES+=		${DISTNAME}.tar.gz ${SSP_PATCH}
SITES_protector-2.95.3-5.tar.gz=	http://www.trl.ibm.com/projects/security/ssp/gcc2_95_3/
PATCHDIR=		../gcc/patches
GCC_FILESDIR=		${FILESDIR}/../../gcc/files

# Please let me know what platforms this package works or doesn't work on.
#ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc
#
# Build error for NetBSD/alpha
NOT_FOR_PLATFORM=	NetBSD-*-alpha \
			NetBSD-*-powerpc NetBSD-*-macppc \
			NetBSD-*-prep NetBSD-*-bebox NetBSD-*-ofppc \
			NetBSD-*-amigappc NetBSD-*-sandpoint

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM} \
			--prefix=${GCC_PREFIX} \
			--enable-shared
CONFIGURE_SCRIPT=	${SRCDIR}/configure
INFO_FILES=		# Not instal info files.

MESSAGE_SUBST+=		MAKE=${MAKE} \
			PKGBASENAME=${PKGBASENAME}
PLIST_SUBST+=		PKGBASENAME=${PKGBASENAME}
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != SunOS)
CONFIGURE_ARGS+=	--with-gnu-as --with-gnu-ld

GCC_PREFIX=		${LOCALBASE}/${PKGBASENAME}
.else
.if (${CC} != gcc)
ALL_TARGET=		bootstrap
.endif
GCC_PREFIX=		${LOCALBASE}
PLIST_SRC=		${PKGDIR}/PLIST.SunOS
PLIST_SUBST+=		GCC_VERSION=${GCC_VERSION}
MESSAGE=		${PKGDIR}/MESSAGE.SunOS
CONFLICTS+=		gcc-[0-9]* pgcc-[0-9]*
.endif

post-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC}/../${DISTNAME}/gcc/config; \
	${CP} ${GCC_FILESDIR}/xm-netbsd.h .; \
	${CP} ${GCC_FILESDIR}/xm-target64.h .; \
	for FILE in ${GCC_FILESDIR}/*_* ; do \
	  ARCH=`basename $${FILE} | cut -d_ -f1`; \
	  DEST=`basename $${FILE} | sed -e "s/$${ARCH}_//"`; \
	  ${MKDIR} $${ARCH}; \
	  ${CP} $${FILE} $${ARCH}/$${DEST}; \
	done; \
	cd ${WRKSRC}/../${DISTNAME}; \
	for i in gcc/config/alpha/netbsd-elf.h gcc/config/arm/t-netbsd \
		gcc/config/mips/x-netbsd libf2c/libF77/dtime_.c libf2c/libF77/etime_.c; do \
	  ${RM} $${i};\
	done

post-patch:
	${ECHO} "bogus" >${WRKSRC}/../${DISTNAME}/gcc/cstamp-h.in
	cd ${WRKDIR} && ${GTAR} xzf ${_DISTDIR}/${SSP_PATCH}
	${CP} ${WRKDIR}/protector.c ${WRKDIR}/protector.h ${WRKDIR}/${DISTNAME}/gcc/
	${PATCH} -p0 -d ${WRKDIR}/${DISTNAME} --forward --quiet -E < ${WRKDIR}/protector.dif
	${PATCH} -p0 -d ${WRKDIR}/${DISTNAME} --forward --quiet -E < ${WRKDIR}/protectonly.dif

.if (${OPSYS} != SunOS)
post-build:
	for FILE in ${FILESDIR}/gcc.mk; do \
	  ${SED} -e 's#@@MAKE@@#${MAKE}#g' \
		 -e 's#@@PKGBASENAME@@#${PKGBASENAME}#g' \
		 -e 's#@@PREFIX@@#${PREFIX}#g' \
	   <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done
	@echo "===> Check whether stack protection works or not"
	${WRKSRC}/gcc/xgcc -B${WRKSRC}/gcc/ -O2 -o ${WRKDIR}/buffer ${FILESDIR}/buffer.c
	ulimit -c 0 && ${WRKDIR}/buffer abcdefghijklmnopqrstuvwxyz  2> ${WRKDIR}/output || true
	@if [ x"`/bin/cat ${WRKDIR}/output`" = "x: stack smashing attack in function main" ]; then \
	    echo "===> Stack protection succeeded."; \
	    exit 0; \
	else \
	    echo "**** Stack protection failed."; \
	    exit 1; \
	fi
.endif

pre-install:
#	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} any PRE-INSTALL
#	This is not needed because of no info.

.if (${OPSYS} != SunOS)
post-install:
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${GCC_VERSION}/include/curses.h ${PREFIX}/${PKGBASENAME}/bin/cc
	${LN} -s gcc ${PREFIX}/${PKGBASENAME}/bin/cc
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGBASENAME}.mk
	${RM} -fr ${GCC_PREFIX}/info
.else
# remove empy file and directories that show up when one
# does make install; make deinstall; make install
post-install:
	-cd ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}/include && \
	${RM} -f fixed && \
	${RMDIR} v7 v9
.endif

.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
