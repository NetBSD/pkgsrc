# $NetBSD: version.mk,v 1.3 2020/12/18 19:58:31 nia Exp $

LUA_VERSION=	5.4.2

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
