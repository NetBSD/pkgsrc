# $NetBSD: Makefile,v 1.3 2005/01/26 03:41:43 jschauma Exp $

DISTNAME=		nspr-4.4.1
CATEGORIES=		devel
MASTER_SITES?=		${MASTER_SIZE_MOZILLA:=nspr/releases/v4.4.1/src}

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/nspr/index.html
COMMENT=		Platform-neutral API for system level and libc like functions

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-debug

AUTOCONF_REQD=		2.13

MAKE_ENV=		DIST=${WRKSRC}/dist
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV=		LIBRUNPATH=${PREFIX}/lib

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX}

pre-configure:
	cd ${WRKSRC}/.. && ${AUTOCONF}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nspr
	(cd ${WRKSRC}/dist/include && ${PAX} -Lrwvpe . ${PREFIX}/include/ )
	(cd ${WRKSRC}/dist/lib && ${PAX} -Lrwvpe . ${PREFIX}/lib/ )
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin


.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ARGS+=	--with-pthreads
.endif

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"

