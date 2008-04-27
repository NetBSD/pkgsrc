# $NetBSD: hacks.mk,v 1.2 2008/04/27 11:00:46 tnn Exp $

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	defined

# Build without optimization. Avoids crash in libgobject on gtk2 initialization.
# Bug is triggered regardless of whether we're using gcc or aCC.
.if !empty(MACHINE_PLATFORM:MHPUX-*-hppa)
PKG_HACKS+=	hppa-codegen
CFLAGS:=	-O0 ${CFLAGS:C/[+,-]O[0-9]?//g}
.endif

# Work around unresolved symbol g_test_config_vars during build
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=		sunpro-visibility
CONFIGURE_ARGS+=	--disable-visibility
.endif

.endif		# GLIB2_HACKS_MK
