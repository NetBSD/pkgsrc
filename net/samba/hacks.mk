# $NetBSD: hacks.mk,v 1.1 2010/03/08 22:19:07 jmmv Exp $

# Enabling PIE results in a 'Unsupported relocation type 6 in non-PLT
# relocations' error under NetBSD/macppc.
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "powerpc"
PKG_HACKS+=		pie
CONFIGURE_ARGS+=	--disable-pie
.endif
