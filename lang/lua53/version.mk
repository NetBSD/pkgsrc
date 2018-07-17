# $NetBSD: version.mk,v 1.6 2018/07/17 21:52:25 alnsn Exp $

LUA_VERSION=	5.3.5

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
