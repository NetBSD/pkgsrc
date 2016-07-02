# $NetBSD: hacks.mk,v 1.1 2016/07/02 14:48:36 joerg Exp $

.if ${OPSYS} == "NetBSD" 
.  include "../../mk/compiler.mk"
.  if ${PKGSRC_COMPILER} == "gcc" && \
      (!empty(CC_VERSION:Mgcc-4.8.*) || !empty(CC_VERSION:Mgcc-5.*))
CONFIGURE_ARGS+=	--disable-precomp-headers
.  endif
.endif
