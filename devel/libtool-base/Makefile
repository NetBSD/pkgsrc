# $NetBSD: Makefile,v 1.13 2002/11/21 00:50:03 jlam Exp $
#

.include "../libtool/Makefile.common"

PKGNAME=        ${PKGPFX:C/-/-base-/}
SVR4_PKGNAME=	ltoob

COMMENT=	Generic shared library support script (the script itself)

CONFLICTS+=	libtool<=1.3.5nb11

USE_BUILDLINK2=	no	# needed for bootstrapping buildlink2

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

.if !empty(MACHINE_PLATFORM:MDarwin-*-*)
DLCOMPATDIR=			${WRKDIR}/.dlcompat
DEPENDS+=			dlcompat>=20020606:../../devel/dlcompat
EVAL_PREFIX+=			DLCOMPAT_PREFIX=dlcompat
DLCOMPAT_PREFIX_DEFAULT=	${LOCALBASE}

pre-configure: dlcompat-buildlink
dlcompat-buildlink:
	cd ${DLCOMPAT_PREFIX};						\
	for file in include/dlfcn.h lib/libdl.*; do			\
		if [ -f "$${file}" ]; then				\
			${MKDIR} ${DLCOMPATDIR}/`${DIRNAME} $${file}`;	\
			${LN} -sf ${DLCOMPAT_PREFIX}/$${file}		\
				${DLCOMPATDIR}/$${file};		\
		fi;							\
	done
.endif

.include "../../mk/bsd.pkg.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-*)
CPPFLAGS:=	-I${DLCOMPATDIR}/include ${CPPFLAGS}
CFLAGS:=	-I${DLCOMPATDIR}/include ${CFLAGS}
LDFLAGS=	-L${DLCOMPATDIR}/lib
.  if ${_USE_RPATH} == "yes"
LDFLAGS+=	-Wl,-R${DLCOMPAT_PREFIX}/lib
.  endif
.else
LDFLAGS=	# empty
.endif
