# $NetBSD: builtin.mk,v 1.7 2005/06/01 18:03:08 jlam Exp $

BUILTIN_PKG:=	x11-links
.include "../../mk/buildlink3/bsd.builtin.mk"

.if !defined(USE_BUILTIN.x11-links)
USE_BUILTIN.x11-links=	no
.endif
MAKEVARS+=	USE_BUILTIN.x11-links
