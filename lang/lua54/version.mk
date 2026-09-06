# $NetBSD: version.mk,v 1.8 2026/09/06 14:32:00 alnsn Exp $

LUA_VERSION=	5.4.9

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
