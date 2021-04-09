# $NetBSD: version.mk,v 1.4 2021/04/09 14:18:12 nia Exp $

LUA_VERSION=	5.4.3

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
