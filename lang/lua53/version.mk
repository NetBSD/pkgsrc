# $NetBSD: version.mk,v 1.3 2015/12/05 22:50:26 alnsn Exp $

LUA_VERSION=	5.3.2

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
