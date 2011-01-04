# $NetBSD: hacks.mk,v 1.5 2011/01/04 09:55:15 adam Exp $

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	# defined

# Build without optimization. Avoids crash in libgobject on gtk2
# initialization. Bug is triggered regardless of whether we're using gcc or
# aCC.
.  if !empty(MACHINE_PLATFORM:MHPUX-*-hppa)
PKG_HACKS+=	hppa-codegen
CFLAGS:=	-O0 ${CFLAGS:C/[+,-]O[0-9]?//g}
.  endif

.  if ${OPSYS} == "Darwin"
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.  endif

# Work around unresolved symbol g_test_config_vars during build
.include "../../mk/compiler.mk"
.  if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=		sunpro-visibility
CONFIGURE_ARGS+=	--disable-visibility
.  endif

.endif
