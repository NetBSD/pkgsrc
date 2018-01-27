# $NetBSD: builtin.mk,v 1.8 2018/01/27 19:07:48 rillig Exp $

BUILTIN_PKG:=	x11-links
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(USE_BUILTIN.x11-links)
USE_BUILTIN.x11-links=	no
.endif
MAKEVARS+=		USE_BUILTIN.x11-links
