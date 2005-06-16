# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:47 jlam Exp $

DISTNAME=		nspr-4.4.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES?=		${MASTER_SIZE_MOZILLA:=nspr/releases/v4.4.1/src}

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/nspr/index.html
COMMENT=		Platform-neutral API for system level and libc like functions

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

USE_TOOLS+=		autoconf213 gmake
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-debug

MAKE_ENV=		DIST=${WRKSRC}/dist
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV=		LIBRUNPATH=${PREFIX}/lib/nspr

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC}/.. && autoconf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nspr
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nspr
	(cd ${WRKSRC}/dist/include && ${PAX} -Lrwpe . ${PREFIX}/include/ )
	(cd ${WRKSRC}/dist/lib && ${PAX} -Lrwpe . ${PREFIX}/lib/nspr/ )
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin


.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ARGS+=	--with-pthreads
.endif

.include "../../mk/bsd.pkg.mk"
