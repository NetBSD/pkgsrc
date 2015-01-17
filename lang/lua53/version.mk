# $NetBSD: version.mk,v 1.1.1.1 2015/01/17 17:50:23 alnsn Exp $

LUA_VERSION=	5.3.0

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
