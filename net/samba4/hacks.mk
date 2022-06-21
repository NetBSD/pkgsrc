# $NetBSD: hacks.mk,v 1.2 2022/06/21 09:47:49 he Exp $

# Enabling PIE results in a 'Unsupported relocation type 6 in non-PLT
# relocations' error under NetBSD/macppc.
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=		pie
CONFIGURE_ARGS+=	--without-pie
.endif
