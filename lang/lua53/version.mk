# $NetBSD: version.mk,v 1.5 2017/02/10 23:01:49 alnsn Exp $

LUA_VERSION=	5.3.4

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
