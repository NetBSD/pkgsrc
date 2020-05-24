# $NetBSD: include-subsub.mk,v 1.1.1.1 2020/05/24 05:35:53 nia Exp $

.if ${.INCLUDEDFROMFILE:T} == "include-sub.mk"
LOG+=		subsub-ok
.else
LOG+=		subsub-fail
.endif
