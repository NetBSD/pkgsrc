# $NetBSD: Makefile,v 1.17 2003/09/18 16:25:12 jmmv Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=        ${PKGPFX:C/-/-base-/}
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

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

.if !empty(MACHINE_PLATFORM:MDarwin-*-*)
.  include "../../devel/dlcompat/buildlink2.mk"
.endif

BUILD_SHLIBTOOL?=	YES
BUILDING_SHLIBTOOL?=	NO

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
