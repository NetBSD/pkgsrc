# $NetBSD: version.mk,v 1.1 2020/06/30 13:16:14 nia Exp $

LUA_VERSION=	5.4.0

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
