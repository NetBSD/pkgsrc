# $NetBSD: version.mk,v 1.2 2026/09/08 19:58:28 alnsn Exp $

LUA_VERSION=	5.5.1

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
