# $NetBSD: Makefile,v 1.45 2002/09/09 03:23:06 dmcmahill Exp $

# Make sure that the version number in "Makefile.gcc" matches this.
DISTNAME=		gcc-2.95.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/}

#
# Synced from patches against main source tree as of:
#
# 03/28/02
MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

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
PLIST_SRC=              ${WRKDIR}/PLIST_DYNAMIC
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
	${CP} ${FILESDIR}/xm-target64.h .; \
	for FILE in ${FILESDIR}/*_* ; do \
	  ARCH=`basename $${FILE} | cut -d_ -f1`; \
	  DEST=`basename $${FILE} | sed -e "s/$${ARCH}_//"`; \
	  ${MKDIR} $${ARCH}; \
	  ${CP} $${FILE} $${ARCH}/$${DEST}; \
	done; \
	cd ${WRKSRC}/../${DISTNAME}; \
	for i in gcc/config/alpha/netbsd-elf.h gcc/config/arm/t-netbsd gcc/config/mips/x-netbsd libf2c/libF77/dtime_.c libf2c/libF77/etime_.c; do \
	  ${RM} $${i};\
	done

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
.	if exists(/usr/include/g++/FlexLexer.h)
		${LN} -s /usr/include/g++/FlexLexer.h \
			 ${PREFIX}/${PKGNAME}/include/g++-3/FlexLexer.h
.	endif
	${RM} -f ${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}/include/curses.h ${PREFIX}/${PKGNAME}/bin/cc
	${LN} -s gcc ${PREFIX}/${PKGNAME}/bin/cc
	${INSTALL_DATA} ${WRKDIR}/gcc.mk ${PREFIX}/etc/${PKGNAME}.mk
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${PREFIX}/${PKGNAME} -type f -print | ${SORT} -r | ${SED} 's;${PREFIX}/;;g' >> ${PLIST_SRC}
	${FIND} ${PREFIX}/${PKGNAME} -type l -print | ${SORT} -r | ${SED} 's;${PREFIX}/;;g' >> ${PLIST_SRC}
	${FIND} ${PREFIX}/${PKGNAME} -type d -print | ${SORT} -r | ${SED} 's;${PREFIX}/;@dirrm ;g' >> ${PLIST_SRC}
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
LDFLAGS=		${_STRIPFLAG_CC}
