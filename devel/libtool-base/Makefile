# $NetBSD: Makefile,v 1.9.2.3 2002/06/23 18:44:31 jlam Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=        ${PKGPFX:C/-/-base-/}
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

USE_BUILDLINK2=	# defined

test: build
	cd ${WRKSRC} && ${MAKE} check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-1.4-sparc} != "" || \
	${MACHINE_PLATFORM:MNetBSD-1.4.[12]-sparc} != ""
DEPENDS+=	c++rt0>=1.0:../../sysutils/c++rt0
.endif

.if ${MACHINE_PLATFORM:MDarwin-*-*} != ""
.include "../../devel/dlcompat/buildlink.mk"
.endif

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif
.else
CONFIGURE_ARGS=	--enable-ltdl-install
.endif

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# Blank
