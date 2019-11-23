# $NetBSD: hacks.mk,v 1.2 2019/11/23 19:41:02 gdt Exp $

.if ${OPSYS} == "NetBSD" 
.  include "../../mk/compiler.mk"
.  if !(${PKGSRC_COMPILER:Mgcc}) && \
      (!empty(CC_VERSION:Mgcc-4.8.*) || !empty(CC_VERSION:Mgcc-5.*))
CONFIGURE_ARGS+=	--disable-precomp-headers
.  endif
.endif
