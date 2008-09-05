# $NetBSD: hacks.mk,v 1.4 2008/09/05 15:33:01 tron Exp $

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	# defined

# Build without optimization. Avoids crash in libgobject on gtk2
# initialization. Bug is triggered regardless of whether we're using gcc or
# aCC.
.  if !empty(MACHINE_PLATFORM:MHPUX-*-hppa)
PKG_HACKS+=	hppa-codegen
CFLAGS:=	-O0 ${CFLAGS:C/[+,-]O[0-9]?//g}
.  endif

# "glib2" supports support for Universal Binaries. But a lot of packages
# using it (e.g. "gtk2+") don't support it. We therefore disable it.

.  if ${OPSYS} == "Darwin"
PKG_HACKS+=	darwin-no-universal
.    if ${MACHINE_ARCH} == "powerpc"
CONFIGURE_ENV+=	ac_cv_c_bigendian=yes
.    else
CONFIGURE_ENV+=	ac_cv_c_bigendian=no
.    endif
.  endif

# Work around unresolved symbol g_test_config_vars during build
.include "../../mk/compiler.mk"
.  if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=		sunpro-visibility
CONFIGURE_ARGS+=	--disable-visibility
.  endif

.endif
