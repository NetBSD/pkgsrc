# $NetBSD: version.mk,v 1.4 2016/06/06 22:18:07 alnsn Exp $

LUA_VERSION=	5.3.3

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
