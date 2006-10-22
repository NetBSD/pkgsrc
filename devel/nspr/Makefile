# $NetBSD: Makefile,v 1.17 2006/10/22 15:23:27 dmcmahill Exp $

DISTNAME=		nspr-4.6.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA:S/mozilla\//nspr\//g:=v4.6.1/src/}

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/nspr/index.html
COMMENT=		Platform-neutral API for system level and libc like functions

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/nsprpub/build

USE_TOOLS+=		autoconf213 gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-debug

MAKE_ENV+=		DIST=${WRKSRC:Q}/dist
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=		LIBRUNPATH=${PREFIX:Q}/lib/nspr

.include		"../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

INSTALLATION_DIRS=	bin

# see ${WRKSRC}/nspr-4.6.1/mozilla/nsprpub/pr/src/md/unix/Makefile.in
# for the bit about 32-bit sun4u machines installing an extra file.
# That is why we have this specific test and modify the PLIST
.if ${OPSYS} == "SunOS" 
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  else
HW_CLASS!=	${UNAME} -m
.    if ${HW_CLASS} == "sun4u"
SUN4U_32=
.    endif
.  endif
.endif

SUN4U_32?=		@comment
PLIST_SUBST+=		SUN4U_32=${SUN4U_32}

.if ${OPSYS} == "Darwin" && exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=	/Developer/Headers/FlatCarbon
.endif

pre-configure:
	cd ${WRKSRC}/.. && autoconf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/nspr
	${INSTALL_DATA_DIR} ${PREFIX}/lib/nspr
	(cd ${WRKSRC}/dist/include && ${PAX} -Lrwpe . ${PREFIX}/include/ )
	(cd ${WRKSRC}/dist/lib && ${PAX} -Lrwpe . ${PREFIX}/lib/nspr/ )
	${INSTALL_SCRIPT} ${WRKSRC}/config/nspr-config ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig
	set -e; \
	{ ${ECHO} "Name: NSPR"; \
	  ${ECHO} "Description: The Netscape Portable Runtime"; \
	  ${ECHO} "Version: ${PKGVERSION}"; \
	  ${ECHO} "Cflags: -I${PREFIX}/include/nspr"; \
	  ${ECHO} "Libs: -L${PREFIX}/lib/nspr" \
	      "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr" \
	      "-lplds4 -lplc4 -lnspr4 "${BUILDLINK_LIBS.pthread:Q}; \
	} >${PREFIX}/lib/pkgconfig/nspr.pc

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ARGS+=	--with-pthreads
.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
