# $NetBSD: hacks.mk,v 1.4 2023/04/29 08:01:06 wiz Exp $

# Enabling PIE results in a 'Unsupported relocation type 6 in non-PLT
# relocations' error under NetBSD/powerpc < 9.0.
.if ${MACHINE_PLATFORM:MNetBSD-[1-8].*-powerpc}
PKG_HACKS+=		pie
CONFIGURE_ARGS+=	--without-pie
.endif
