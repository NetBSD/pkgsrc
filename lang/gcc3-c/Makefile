# $NetBSD: Makefile,v 1.1 2003/07/06 12:15:07 drochner Exp $
#

DISTNAME=		gcc-3.3
PKGNAME=		gcc3-c-3.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

# XXX just because of .info files
#CONFLICTS+=		gcc-3* pgcc-[0-9]* gcc3-[0-9]*

NOT_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}

# as this is named gcc3, use DISTNAME instead.
FILES_SUBST+=		PKGNAME_NOREV=${DISTNAME} GCC_PREFIX=${GCC_PREFIX}
MESSAGE_SUBST+=		PKGNAME_NOREV=${DISTNAME}

TEXINFO_REQD=		4.2
INFO_FILES=		cpp.info gcc.info

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/pthread.h)
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.else
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
.endif
CONFIGURE_ARGS+=	--enable-languages="c"

.if ${OPSYS} == "NetBSD" && !defined(USE_BINUTILS)
AS_VERSION!=		${AS} --version | ${AWK} '{				\
			    split($$3, v, /[.]/);				\
			    printf "%02d%02d%02d%02d\n",v[1],v[2],v[3],v[4];	\
			    exit;						\
			}'
USE_BINUTILS!=		${TEST} ${AS_VERSION} -lt 02130201 && echo YES || echo NO
.endif

.if defined(USE_BINUTILS) && ${USE_BINUTILS} == "YES"
DEPENDS=		binutils>=2.13.2.1:../../devel/binutils
CONFIGURE_ARGS+=	--with-as=${PREFIX}/${MACHINE_GNU_PLATFORM}/bin/as
#.  include "../../devel/binutils/buildlink2.mk"
.endif

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-shared
.else
.  if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-shared
.  else
CONFIGURE_ARGS+=	--disable-shared
.  endif
.  if ${CC:M*gcc*} == ""
ALL_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/gcc3
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${MACHINE_GNU_PLATFORM}/${PKGVERSION}

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/gcc_update --touch

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk

post-install:
.if ${OPSYS} == "SunOS"
	-cd ${GCC_ARCHDIR}/include && ${RM} -f fixed && ${RMDIR} v7 v9
.endif
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/gcc
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${PREFIX}/share/examples/gcc/mk.conf
	${LN} -f ${GCC_PREFIX}/bin/gcc ${GCC_PREFIX}/bin/cc
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} \( -type f -o -type l \) -print		\
		| ${SORT} | ${SED} -e "s,${PREFIX}/,,g"			\
		>> ${PLIST_SRC}
	${FIND} ${GCC_PREFIX} -type d -print				\
		| ${SORT} -r | ${SED} -e "s,${PREFIX}/,@dirrm ,g"	\
		>> ${PLIST_SRC}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

# Make bootstrap with compiler != gcc possible.
CONFIGURE_ENV+=	LDFLAGS="${_STRIPFLAG_CC}"
MAKE_ENV+=	GCC_PREFIX="${GCC_PREFIX}"
