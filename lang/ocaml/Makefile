# $NetBSD: Makefile,v 1.84 2013/03/14 14:37:56 is Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	-no-tk
CONFIGURE_ARGS+=	-cc ${CC}
CONFIGURE_ENV+=		disable_x11=yes

BUILD_TARGET=		world
MAKE_JOBS_SAFE=		no
UNLIMIT_RESOURCES=	stacksize

###
### PLIST components
###

# Stub libraries for functions missing from base system.
.if !empty(MACHINE_PLATFORM:MDarwin-*-powerpc) || \
    !empty(MACHINE_PLATFORM:MDarwin-9.*-i386) || \
    !empty(MACHINE_PLATFORM:MDarwin-1[0-9].*-x86_64) || \
    ${OPSYS} == "DragonFly" || ${OPSYS} == "NetBSD" || \
    ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS" || \
    ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.stub
.endif

# Optional components built only on certain platforms.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "arm") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
BUILD_TARGET+=	opt opt.opt
PLIST_SRC+=	${PKGDIR}/PLIST.opt
.  if empty(MACHINE_PLATFORM:MDarwin-*-powerpc) && \
      empty(MACHINE_PLATFORM:MSunOS-*-i386) && \
      empty(MACHINE_PLATFORM:MSunOS-*-x86_64) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-powerpc) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-x86_64) && \
      empty(MACHINE_PLATFORM:MFreeBSD-*-x86_64) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-arm) && \
      empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
PLIST_SRC+=	${PKGDIR}/PLIST.prof
.  endif
.endif

# XXX This conditional is not complete.  It should match the
# conditional in ocaml-x.y.z/configure.
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDarwin-*-*)
PLIST_SRC+=	${PKGDIR}/PLIST.natdynlink
.  endif
.endif

# Common ocaml files.
PLIST_SRC+=	${PKGDIR}/PLIST

# This is needed because ${WRKSRC}/build/partial-install.sh uses
# $PWD as part of its script.  However, with /bin/sh on SunOS
# (cd work/foo-1.0 && echo $PWD) will show that the value of PWD is
# set before the cd takes place and is then passed down.  So the end
# result is when ./build/partial-install.sh is called, PWD is set
# to /usr/pkgsrc/devel/ocaml instead of ${WRKSRC}.  /bin/ksh, which
# is what ${SH} is on SunOS, doesn't exhibit this behaviour.
.if ${OPSYS} == "SunOS"
INSTALL_MAKE_FLAGS+=	SHELL=${SH:Q}
.endif

.if ${OPSYS} == "NetBSD"
EXTRA_RT_LIBS=	-lcurses
.else
EXTRA_RT_LIBS=
.endif

SUBST_CLASSES+=		extra-rt-libs
SUBST_FILES.extra-rt-libs=	bytecomp/bytelink.ml
SUBST_SED.extra-rt-libs+=	-e 's,@EXTRA_RT_LIBS@,${EXTRA_RT_LIBS},g'
SUBST_STAGE.extra-rt-libs=	pre-configure

do-test:
	cd ${WRKSRC}/testsuite && ${MAKE_PROGRAM} all

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
