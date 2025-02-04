# $NetBSD: options.mk,v 1.1 2025/02/04 08:47:25 imil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dinit
PKG_SUPPORTED_OPTIONS=	static kqueue

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
LDFLAGS+=	-static
.endif

.if !empty(PKG_OPTIONS:Mkqueue) && \
	(${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD")
CPPFLAGS+=	-DDASYNQ_HAVE_KQUEUE=1
.endif
