# $NetBSD: Makefile,v 1.5 2001/02/28 15:19:52 tron Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=        ${PKGPFX:C/-/-base-/}${PKGREV}

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<1.3.5nb11

test: build
	cd ${WRKSRC} && ${MAKE} check

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-1.4-sparc} != "" || \
	${MACHINE_PLATFORM:MNetBSD-1.4.[12]-sparc} != ""
DEPENDS+=	c++rt0>=1.0:../../sysutils/c++rt0
.endif

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS=	--disable-shared
.endif
.else
CONFIGURE_ARGS=	--enable-ltdl-install
.endif

.if (${OPSYS} == SunOS)
PLIST_SRC=	${PKGDIR}/PLIST.SunOS
.endif

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# Blank
