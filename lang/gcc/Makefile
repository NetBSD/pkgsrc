# $NetBSD: Makefile,v 1.48 2002/10/20 20:40:11 jlam Exp $

# Make sure that the version number in "Makefile.gcc" matches this.
DISTNAME=		gcc-2.95.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}
#
# Synced from patches against main source tree as of 2002-03-28
#
MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	${SRCDIR}/configure
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-shared

PLIST_SUBST+=		GCC_VERSION=${PKGVERSION}
SRCDIR=			${WRKDIR}/${DISTNAME}
WRKSRC=			${WRKDIR}/objdir

INFO_FILES=		chill.info cpp.info g77.info gcc.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CONFLICTS+=		gcc-[0-9]* pgcc-[0-9]*
.  if ${CC} != "gcc"
ALL_TARGET=		bootstrap
.  endif
GCC_PREFIX=		${PREFIX}
PLIST_SRC=		${PKGDIR}/PLIST.SunOS
MESSAGE_SRC=		${PKGDIR}/MESSAGE.SunOS
.else
GCC_PREFIX=		${PREFIX}/${PKGNAME}
CONFIGURE_ARGS+=	--with-gnu-as
CONFIGURE_ARGS+=	--with-gnu-ld
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
PLIST_SRC=              ${WRKDIR}/PLIST_DYNAMIC
.endif

GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}
FILES_SUBST+=	GCC_PREFIX=${GCC_PREFIX}

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/xm-netbsd.h ${SRCDIR}/gcc/config
	${CP} ${FILESDIR}/xm-target64.h ${SRCDIR}/gcc/config
	for file in ${FILESDIR}/*_* ; do \
		arch=`${BASENAME} $${file} | ${SED} -e "s/_.*//"`;	\
		dest=`${BASENAME} $${file} | ${SED} -e "s/$${arch}_//"`; \
		${MKDIR} ${SRCDIR}/gcc/config/$${arch};			\
		${CP} $${file} ${SRCDIR}/gcc/config/$${arch}/$${dest};	\
	done
	${RM} ${SRCDIR}/gcc/config/alpha/netbsd-elf.h
	${RM} ${SRCDIR}/gcc/config/arm/t-netbsd
	${RM} ${SRCDIR}/gcc/config/mips/x-netbsd
	${RM} ${SRCDIR}/libf2c/libF77/dtime_.c
	${RM} ${SRCDIR}/libf2c/libF77/etime_.c

pre-configure:
	${ECHO} "bogus" > ${SRCDIR}/gcc/cstamp-h.in

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc.mk > ${WRKDIR}/gcc.mk

.if (${OPSYS} == SunOS)
#
# remove empty file and directories that show up when one does:
#	make install; make deinstall; make install
#
post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.else
post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
.  if exists(/usr/include/g++/FlexLexer.h)
	${LN} -fs /usr/include/g++/FlexLexer.h				\
		${GCC_PREFIX}/include/g++-3/FlexLexer.h
.  endif
	${RM} -f ${GCC_ARCHDIR}/include/curses.h ${GCC_PREFIX}/bin/cc
	${LN} -s gcc ${GCC_PREFIX}/bin/cc
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}
.endif

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
LDFLAGS=		${_STRIPFLAG_CC}
