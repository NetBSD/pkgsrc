# $NetBSD: Makefile,v 1.1.1.1 2003/01/06 07:42:27 uebayasi Exp $

# Make sure that the version number in "Makefile.gcc" matches this.
DISTNAME=		gcc-3.2.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}
MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

# XXX Solaris not tested
ONLY_FOR_PLATFORM=	NetBSD-*

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-shared

FILES_SUBST+=		PKGNAME=${PKGNAME}
PLIST_SUBST+=		GCC_VERSION=${PKGVERSION}

INFO_FILES=		cpp.info g77.info gcc.info gcj.info

.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == "SunOS"
#CONFLICTS+=		gcc-[0-9]* pgcc-[0-9]*
#.  if ${CC} != "gcc"
#ALL_TARGET=		bootstrap
#.  endif
#GCC_PREFIX=		${PREFIX}
#PLIST_SRC=		${PKGDIR}/PLIST.SunOS
#MESSAGE_SRC=		${PKGDIR}/MESSAGE.SunOS
#.else
GCC_PREFIX=		${PREFIX}/${PKGNAME}
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
PLIST_SRC=              ${WRKDIR}/PLIST_DYNAMIC
#.endif

GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}
FILES_SUBST+=	GCC_PREFIX=${GCC_PREFIX}

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	${TOUCH} ${TOUCH_FLAGS}	${WRKSRC}/gcc/c-gperf.h
	${ECHO} "bogus" > ${WRKSRC}/gcc/cstamp-h.in

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${PREFIX}/etc/${PKGNAME}.mk
	${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc
#	${LN} -f ${GCC_PREFIX}/bin/g77 ${GCC_PREFIX}/bin/f77
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
