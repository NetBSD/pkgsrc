# $NetBSD: Makefile,v 1.2 2003/07/06 12:31:59 grant Exp $
#

DISTNAME=		gcc-3.3
PKGNAME=		gcc3-objc-3.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

NOT_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-languages="objc"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/pthread.h)
GCC_PLATFORM=	${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.else
GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM}
PLIST_SUBST+=	GCC_PLATFORM=${GCC_PLATFORM}

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

# as this is named gcc3, use DISTNAME instead.
GCC_PREFIX=	${PREFIX}/gcc3
GCC_VERSION=	${PKGVERSION:C|nb*||}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${GCC_PLATFORM}/${GCC_VERSION}

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/gcc_update --touch

do-build:
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h)
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} objc)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} all-target-libobjc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/cc1obj ${GCC_ARCHDIR}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libobjc)

.include "../../lang/gcc3-c/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
