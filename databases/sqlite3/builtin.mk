# $NetBSD: builtin.mk,v 1.1 2011/11/09 01:30:19 jnemeth Exp $

BUILTIN_PKG:=	sqlite3

PKGCONFIG_FILE.sqlite3=	/usr/lib/pkgconfig/sqlite3.pc
PKGCONFIG_BASE.sqlite3=	/usr

.include "../../mk/buildlink3/pkgconfig-builtin.mk"
