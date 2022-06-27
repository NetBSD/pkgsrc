# $NetBSD: hacks.mk,v 1.2 2022/06/27 20:59:39 rin Exp $

# Enabling PIE results in a 'Unsupported relocation type 6 in non-PLT
# relocations' error under NetBSD/powerpc < 9.0.
.if !empty(MACHINE_PLATFORM:MNetBSD-[1-8].*-powerpc)
PKG_HACKS+=		pie
CONFIGURE_ARGS+=	--disable-pie
.endif
