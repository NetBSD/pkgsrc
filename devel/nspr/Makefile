# $NetBSD: Makefile,v 1.25 2008/01/29 11:37:35 joerg Exp $

DISTNAME=		nspr-4.6.7
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_MOZILLA_ALL:=nspr/releases/v4.6.7/src/}

MAINTAINER=		mjl@luckie.org.nz
HOMEPAGE=		http://www.mozilla.org/projects/nspr/index.html
COMMENT=		Platform-neutral API for system level and libc like functions

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME}/mozilla/nsprpub
CONFIGURE_DIRS=		build

USE_TOOLS+=		autoconf213 gmake
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--disable-debug

MAKE_ENV+=		DIST=${WRKSRC:Q}/dist
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=		LIBRUNPATH=${PREFIX:Q}/lib/nspr

.include		"../../mk/bsd.prefs.mk"

CFLAGS+=		-D_DONT_CAST_PTHREAD_T	# XXX pthread_t can be 64-bit

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

SUN4U_32?=		"@comment "
PLIST_SUBST+=		SUN4U_32=${SUN4U_32}

.if ${OPSYS} == "Darwin" && exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=	/Developer/Headers/FlatCarbon

SUBST_CLASSES+=		libpath
SUBST_STAGE.libpath=	post-configure
SUBST_FILES.libpath=	build/config/autoconf.mk
SUBST_SED.libpath=	-e 's,@executable_path/$$@,${PREFIX}/lib/nspr/$$(notdir $$@),'
.endif

INSTALLATION_DIRS=	bin include/nspr lib/nspr lib/pkgconfig

post-extract:
	${CHMOD} -R g-w ${WRKSRC}
	${CHMOD} -x ${WRKSRC}/pr/include/prvrsion.h

pre-configure:
	cd ${WRKSRC} && autoconf

do-install:
	(cd ${WRKSRC}/build/dist/include && ${PAX} -Lrwpe . ${DESTDIR}${PREFIX}/include/ )
	(cd ${WRKSRC}/build/dist/lib && ${PAX} -Lrwpe . ${DESTDIR}${PREFIX}/lib/nspr/ )
	${INSTALL_SCRIPT} ${WRKSRC}/build/config/nspr-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/pkgconfig
	set -e; \
	{ ${ECHO} "Name: NSPR"; \
	  ${ECHO} "Description: The Netscape Portable Runtime"; \
	  ${ECHO} "Version: ${PKGVERSION}"; \
	  ${ECHO} "Cflags: -I${PREFIX}/include/nspr"; \
	  ${ECHO} "Libs: -L${PREFIX}/lib/nspr" \
	      "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr" \
	      "-lplds4 -lplc4 -lnspr4 "${BUILDLINK_LIBS.pthread:Q}; \
	} >${DESTDIR}${PREFIX}/lib/pkgconfig/nspr.pc

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=	--without-pthreads
.else
CONFIGURE_ARGS+=	--with-pthreads
.include "../../mk/pthread.buildlink3.mk"
# XXX TODO
#.include "../../mk/resolv.buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
