# $NetBSD: Makefile,v 1.32.2.1 2010/02/17 22:24:32 spz Exp $
#

.include "../../devel/xulrunner/dist.mk"
PKGNAME=	${DISTNAME:S/firefox/nspr/:S/3.5/${NSPR_RELEASE}/:S/.source//}
NSPR_RELEASE=	4.8.3
CATEGORIES=	devel

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozilla.org/projects/nspr/index.html
COMMENT=	Platform-neutral API for system level and libc like functions

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		nsprpub

USE_TOOLS+=		autoconf213 gmake perl
REPLACE_PERL+=		nsprpub/pr/src/misc/compile-et.pl

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--with-pthreads
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/nspr
CONFIGURE_ENV+=		LIBRUNPATH=${PREFIX:Q}/lib/nspr

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			nspr-config
SUBST_STAGE.nspr-config=	pre-configure
SUBST_MESSAGE.nspr-config=	Fixing nspr-config run path
SUBST_FILES.nspr-config=	nsprpub/config/nspr-config.in
SUBST_SED.nspr-config=		-e 's|-L$$libdir|"${COMPILER_RPATH_FLAG}$$libdir -L$$libdir"|g'

.if ${OBJECT_FMT} == "ELF"
SO_SUFFIX=		so
.elif ${OBJECT_FMT} == "Mach-O"
SO_SUFFIX=		dylib
.else
SO_SUFFIX=		so.1.0
.endif
PLIST_SUBST+=		SO_SUFFIX=${SO_SUFFIX:Q}

PLIST_VARS+=		sun4u_32
# see nsprpub/pr/src/md/unix/Makefile.in
# for the bit about 32-bit sun4u machines installing an extra file.
# That is why we have this specific test and modify the PLIST
.if ${OPSYS} == "SunOS"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  else
HW_CLASS!=	${UNAME} -m
.    if ${HW_CLASS} == "sun4u"
PLIST.sun4u_32=                yes
.    endif
.  endif
.endif

.if ${OPSYS} == "Linux"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endif

.if ${OPSYS} == "Darwin" && exists(/Developer/Headers/FlatCarbon)
BUILDLINK_PASSTHRU_DIRS+=	Developer/Headers/FlatCarbon
.endif

pre-configure:
# sanity check: make sure the nspr release is what we think it is.
	@set -e; if [ '"${NSPR_RELEASE}"' !=			\
	  "`${AWK} '/PR_VERSION/ {print $$3}' <			\
	    ${WRKSRC}/nsprpub/pr/include/prinit.h`" ]; then	\
	  ${ECHO} "package is out of date";			\
	  exit 1;						\
	fi
	cd ${WRKSRC}/nsprpub && autoconf

post-build:
	set -e; ( \
	  ${ECHO} "Name: NSPR"; \
	  ${ECHO} "Description: The Netscape Portable Runtime";	\
	  ${ECHO} "Version: ${NSPR_RELEASE}";			\
	  ${ECHO} "Cflags: -I${PREFIX}/include/nspr";		\
	  ${ECHO} "Libs: -L${PREFIX}/lib/nspr"			\
	    "${COMPILER_RPATH_FLAG}${PREFIX}/lib/nspr"		\
	    "-lplds4 -lplc4 -lnspr4 -pthread"			\
	) > ${WRKDIR}/nspr.pc

INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKDIR}/nspr.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
