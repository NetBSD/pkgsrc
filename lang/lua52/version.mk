# $NetBSD: version.mk,v 1.3 2015/03/08 10:55:19 alnsn Exp $

LUA_VERSION=	5.2.4

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
