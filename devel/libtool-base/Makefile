# $NetBSD: Makefile,v 1.54 2005/01/19 16:11:26 jschauma Exp $
#

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
PKGREVISION=	9
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

TEST_TARGET=	check

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	--disable-shared
BUILD_SHLIBTOOL=	NO
.  endif
.endif
CONFIGURE_ARGS+=	--disable-ltdl-install
BUILD_SHLIBTOOL?=	YES

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=        --cache-file=/dev/null
.endif

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
