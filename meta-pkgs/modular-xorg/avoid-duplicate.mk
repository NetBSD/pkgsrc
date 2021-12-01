# $NetBSD: avoid-duplicate.mk,v 1.1 2021/12/01 12:48:17 nia Exp $

BUILTIN_PKG=		${X11_BUILTIN_NAME}

.include "${.INCLUDEDFROMDIR}/builtin.mk"

.if ${X11_TYPE} == "native" && ${USE_BUILTIN.${X11_BUILTIN_NAME}} == "yes"
RESTRICTED=		"Package set is using native X11 component"
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
.endif
