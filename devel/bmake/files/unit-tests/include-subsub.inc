# $NetBSD: include-subsub.inc,v 1.1 2024/07/15 09:10:20 jperkin Exp $

.if ${.INCLUDEDFROMFILE} == "include-sub.inc"
.MAKEFLAGS: -dp
.  info subsub-ok
.MAKEFLAGS: -d0
.else
.  warning subsub-fail(${.INCLUDEDFROMFILE})
.endif
