# $NetBSD: Makefile,v 1.43 2004/10/12 04:41:39 tv Exp $
#

PKGNAME=	${DISTNAME:C/-/-base-/}
PKGREVISION=	4
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

# We are going to want libtool to find the same versions of the C, C++,
# and Fortran compilers.
#
USE_LANGUAGES=	c c++ fortran

.include "../../devel/libtool/Makefile.common"

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	--disable-shared
BUILD_SHLIBTOOL=	NO
.  endif
.else
CONFIGURE_ARGS+=	--enable-ltdl-install
.endif

CONFIGURE_ARGS+=	--with-tags=CXX,F77,GCJ

# The configure script persists in trying to find the path to ld, which
# always ends up in ${BUILDLINK_DIR}.  Prevent it from caring.
#
CONFIGURE_ENV+=		lt_cv_path_LD=${LD:Q}

# The configure script persists in trying to find the path to sed or gsed,
# which breaks when SED is nbsed.  Tell it explicitly to use the sed
# named by ${SED}.
#
CONFIGURE_ENV+=		SED=${SED:Q}
CONFIGURE_ENV+=		lt_cv_path_SED=${SED:Q}

# The configure script doesn't seem to be working out the need for -p
# or -B, so tell it
.if ${OPSYS} == "SunOS"
CONFIGURE_ENV+=		lt_cv_path_NM="nm -p"
.elif ${OPSYS} == "IRIX"
CONFIGURE_ENV+=		lt_cv_path_NM="nm -B"
.endif

BUILD_SHLIBTOOL?=	YES

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

.include "../../devel/dlcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
