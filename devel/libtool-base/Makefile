# $NetBSD: Makefile,v 1.62 2005/05/18 11:57:01 adam Exp $

.include "../../devel/libtool/Makefile.common"

#
# HEADS UP!  Before changing PKGREVISION:  Did you remember to merge
# any changes into the m4 manual diffs?  Updating patch-a[bd] is not enough!
#
# See devel/libtool/patches/manual.README for instructions on how to make
# these patch files properly, so that your changes won't be lost completely
# on the next libtool update.
#
PKGNAME=	${DISTNAME:S/-/-base-/}
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

TEST_TARGET=	check

.if ${OPSYS} == "AIX"

# always build libraries and executables that use the runtime linker.
# in addition, disable libtool locking, as the test is broken on AIX,
# and results in files being locked indefinitely.
LDFLAGS+=		-Wl,-brtl
CONFIGURE_ARGS+=	--disable-libtool-lock

.elif ${OPSYS} == "IRIX"

# The MIPSpro compiler doesn't support -c with -o, but the locking
# workaround is itself broken.  Disable it unconditionally.
CONFIGURE_ARGS+=	--disable-libtool-lock

.elif ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	--disable-shared
BUILD_SHLIBTOOL=	NO
.  endif

.endif

CONFIGURE_ARGS+=	--disable-ltdl-install
BUILD_SHLIBTOOL?=	YES

# We are going to want libtool to find the same versions of the C, C++,
# and Fortran compilers.
#
USE_LANGUAGES=		c c++ fortran
CONFIGURE_ARGS+=	--with-tags=CXX,F77,GCJ

.PHONY: fix-libtool
fix-libtool:
	cd ${WRKSRC}; for f in libtool; do				\
		${SED}	-e "s,-L${BUILDLINK_DIR}/lib,," $$f > $$f.new;	\
		if [ -x $$f ]; then ${CHMOD} +x $$f.new; fi;		\
		${MV} -f $$f.new $$f;					\
	done

post-build: fix-libtool

.if ${BUILD_SHLIBTOOL} == "NO"
PLIST_SUBST+=		SHLIBTOOL="@comment "
.else
PLIST_SUBST+=		SHLIBTOOL=

post-build:
	cd ${WRKSRC} && \
		${SED} -e '/^# Whether or not to build static/{n;s/yes/no/;}' \
		< libtool > shlibtool

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/shlibtool ${PREFIX}/bin/shlibtool
.endif

BUILDLINK_DEPMETHOD.dlcompat=	build

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
