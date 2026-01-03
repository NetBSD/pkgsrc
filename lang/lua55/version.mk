# $NetBSD: version.mk,v 1.1 2026/01/03 14:56:10 alnsn Exp $

LUA_VERSION=	5.5.0

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
