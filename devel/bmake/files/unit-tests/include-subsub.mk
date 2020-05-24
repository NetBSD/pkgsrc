# $NetBSD: include-subsub.mk,v 1.2 2020/05/24 11:09:44 nia Exp $

.if ${.INCLUDEDFROMFILE:T} == "include-sub.mk"
LOG+=		subsub-ok
.else
LOG+=		subsub-fail
.endif
