# $NetBSD: options.mk,v 1.25 2025/07/13 17:24:31 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.irssi
PKG_SUPPORTED_OPTIONS=		otr perl irssi-truecolor
PKG_SUGGESTED_OPTIONS=		otr perl irssi-truecolor

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		otr
.if !empty(PKG_OPTIONS:Motr)
PLIST.otr=		yes
# Build it into the main irssi executable instead of a module.
MESON_ARGS+=		-Dwith-otr=yes
# TODO: statically linked previously, but this now gives:
# ld: /usr/lib/libintl.a(sysdep.o): warning: relocation against `sysdep_pair_table' in read-only section `.text'
# ld: /usr/lib/libintl.a(sysdep.o): relocation R_X86_64_PC32 against symbol `sysdep_pair_table' can not be used when making a shared object; recompile with -fPIC
#MESON_ARGS+=		-Dstatic-dependency=yes
# TODO: not sure how to replace this, if at all
#.  if ${USE_CROSS_COMPILE:tl} == "yes"
#CONFIGURE_ARGS+=	LIBGCRYPT_CONFIG=${CROSS_DESTDIR:Q}${BUILDLINK_PREFIX.libgcrypt}/bin/libgcrypt-config
#.  endif
.include "../../chat/libotr/buildlink3.mk"
.else
MESON_ARGS+=		-Dwith-otr=no
.endif

PLIST_VARS+=		perl
.if !empty(PKG_OPTIONS:Mperl)
PLIST.perl=		yes
USE_TOOLS+=		perl:run
.include "../../lang/perl5/buildlink3.mk"
# this is actually the default
# but who knows what may happen in future versions
MESON_ARGS+=		-Dwith-perl=yes
MESON_ARGS+=		-Dwith-perl-lib=vendor
.else
MESON_ARGS+=		-Dwith-perl=no
.endif

.if !empty(PKG_OPTIONS:Mirssi-truecolor)
MESON_ARGS+=		-Denable-true-color=yes
.endif
