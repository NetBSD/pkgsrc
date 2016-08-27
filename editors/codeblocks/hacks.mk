# $NetBSD: hacks.mk,v 1.1 2016/08/27 20:58:41 joerg Exp $

### g++ 4.8 and 5.3 on NetBSD/i386 fails with an internal compiler error
### when PCH is used. Be conservative and disable on all MACHINE_ARCH
### 
.if ${OPSYS} == "NetBSD" 
.  include "../../mk/compiler.mk"
.  if ${PKGSRC_COMPILER} == "gcc" && \
      (!empty(CC_VERSION:Mgcc-4.8.*) || !empty(CC_VERSION:Mgcc-5.*))
CONFIGURE_ARGS+=	--disable-pch
.  endif
.endif
