# $NetBSD: version.mk,v 1.5 2022/03/06 07:46:10 nia Exp $

LUA_VERSION=	5.4.4

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
