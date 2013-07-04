# $NetBSD: version.mk,v 1.3 2013/07/04 18:04:42 adam Exp $

LUA_VERSION=	5.2.2

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
