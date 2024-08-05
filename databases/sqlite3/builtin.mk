# $NetBSD: builtin.mk,v 1.5 2024/08/05 06:32:28 wiz Exp $

BUILTIN_PKG:=	sqlite3

PKGCONFIG_FILE.sqlite3=	/usr/lib/pkgconfig/sqlite3.pc
PKGCONFIG_BASE.sqlite3=	/usr

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

###
### The section below only applies if we are not including this file
### solely to determine whether a built-in implementation exists.
###

CHECK_BUILTIN.sqlite3?=		no
.if !empty(CHECK_BUILTIN.sqlite3:M[nN][oO])

.  if !empty(USE_BUILTIN.sqlite3:M[yY][eE][sS])
BUILDLINK_PREFIX.sqlite3=	/usr
BUILDLINK_FILES.sqlite3+=	lib/pkgconfig/sqlite3.pc
.  endif

.endif  # CHECK_BUILTIN.sqlite3
