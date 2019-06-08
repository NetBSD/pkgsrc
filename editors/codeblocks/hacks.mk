# $NetBSD: hacks.mk,v 1.2 2019/06/08 10:40:53 rillig Exp $

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
