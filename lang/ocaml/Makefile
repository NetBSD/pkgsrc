# $NetBSD: Makefile,v 1.53 2006/12/01 04:12:20 minskim Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	-no-tk
CONFIGURE_ENV+=		disable_x11=yes

BUILD_TARGET=		world

###
### PLIST components
###

# Stub libraries for functions missing from base system.
.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc) || ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

# Optional components built only on certain platforms.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=	opt opt.opt
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.  if empty(MACHINE_PLATFORM:MDarwin-*-*) && \
      empty(MACHINE_PLATFORM:MSunOS-*-i386) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
.endif

# Common ocaml files.
PLIST_SRC+=	${PKGDIR}/PLIST


.include "../../mk/bsd.pkg.mk"
