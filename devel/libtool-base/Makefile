# $NetBSD: Makefile,v 1.28 2004/02/16 20:24:25 jlam Exp $
#

PKGNAME=	${DISTNAME:C/-/-base-/}
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

.if !empty(MACHINE_PLATFORM:MNetBSD-1.4-sparc) || \
    !empty(MACHINE_PLATFORM:MNetBSD-1.4.[12]-sparc)
DEPENDS+=	c++rt0>=1.0:../../sysutils/c++rt0
.endif

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=		--disable-shared
BUILD_SHLIBTOOL=	NO
.  endif
.else
CONFIGURE_ARGS=		--enable-ltdl-install
.endif

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

.if !empty(MACHINE_PLATFORM:MDarwin-*-*)
.  include "../../devel/dlcompat/buildlink3.mk"
.endif

BUILD_SHLIBTOOL?=	YES
BUILDING_SHLIBTOOL?=	NO

.PHONY: fix-libtool
fix-libtool:
	cd ${WRKSRC}; for f in libtool; do				\
		${SED}	-e "s,-L${BUILDLINK_DIR}/lib,," $$f > $$f.new;	\
		if [ -x $$f ]; then ${CHMOD} +x $$f.new; fi;		\
		${MV} -f $$f.new $$f;					\
	done

post-build: fix-libtool

.if ${BUILDING_SHLIBTOOL} == "YES"
CONFIGURE_ARGS+=	--disable-static
.else
SHLIBTOOL_WRKDIR=	${WRKDIR}/shlibtool
SHLIBTOOL_WRKSRC=	${WRKSRC:S/${WRKDIR}/${SHLIBTOOL_WRKDIR}/}
SHLIBTOOL_MAKEFLAGS=	BUILDING_SHLIBTOOL=YES
SHLIBTOOL_MAKEFLAGS+=	WRKDIR=${SHLIBTOOL_WRKDIR}

.  if ${BUILD_SHLIBTOOL} == "NO"
PLIST_SUBST+=		SHLIBTOOL="@comment "
.  else
PLIST_SUBST+=		SHLIBTOOL=

post-build:
	cd ${.CURDIR} && ${MAKE} build ${SHLIBTOOL_MAKEFLAGS}

post-install:
	${INSTALL_SCRIPT} ${SHLIBTOOL_WRKSRC}/libtool			\
		${PREFIX}/bin/shlibtool
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
