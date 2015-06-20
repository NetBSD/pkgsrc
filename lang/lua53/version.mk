# $NetBSD: version.mk,v 1.2 2015/06/20 18:22:56 alnsn Exp $

LUA_VERSION=	5.3.1

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
