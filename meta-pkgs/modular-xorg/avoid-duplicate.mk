# $NetBSD: avoid-duplicate.mk,v 1.2 2022/02/13 10:44:38 nia Exp $

BUILTIN_PKG=		${X11_BUILTIN_NAME}

.include "${.INCLUDEDFROMDIR}/builtin.mk"

.if ${X11_TYPE} == "native" && ${USE_BUILTIN.${X11_BUILTIN_NAME}} == "yes"
PKG_SKIP_REASON+=	"Package set is using native X11 component"
.endif
