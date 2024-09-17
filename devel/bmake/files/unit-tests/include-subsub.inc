# $NetBSD: include-subsub.inc,v 1.2 2024/09/17 11:52:32 jperkin Exp $

.if ${.INCLUDEDFROMFILE} == "include-sub.inc"
.MAKEFLAGS: -dp
.  info subsub-ok
.MAKEFLAGS: -d0
.else
.  warning subsub-fail(${.INCLUDEDFROMFILE})
.endif
