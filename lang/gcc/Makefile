# $NetBSD: Makefile,v 1.38 2002/03/25 14:43:00 cjep Exp $

# Make sure that the version number in "Makefile.gcc" matches this.
DISTNAME=		gcc-2.95.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

# The platforms listed below are the only tested platforms so far.
# If you get gcc working on other platforms, then please add them.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-arm32 SunOS-*-*

USE_GMAKE=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM} \
			--prefix=${GCC_PREFIX} \
			--enable-shared
CONFIGURE_SCRIPT=	${SRCDIR}/configure
INFO_FILES=		chill.info cpp.info g77.info gcc.info

PLIST_SUBST+=		GCC_VERSION=${PKGVERSION}
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
	cd ${WRKSRC}/../${DISTNAME}/gcc/config; \
	${CP} ${FILESDIR}/xm-netbsd.h .; \
	for ARCH in arm arm i386 m68k sh sparc vax; do \
	  ${MKDIR} $${ARCH}; \
	  ${CP} ${FILESDIR}/$${ARCH}_netbsd-elf.h $${ARCH}/netbsd-elf.h; \
	done; \
	${CP} ${FILESDIR}/sparc_netbsd-elf-common.h sparc/netbsd-elf-common.h

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

pre-install:
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} any PRE-INSTALL

.if (${OPSYS} != SunOS)
post-install:
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}/include/curses.h ${PREFIX}/${PKGNAME}/bin/cc
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
.else
# remove empy file and directories that show up when one
# does make install; make deinstall; make install
post-install:
	-cd ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}/include && \
	${RM} -f fixed && \
	${RMDIR} v7 v9
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${STRIPFLAG}
