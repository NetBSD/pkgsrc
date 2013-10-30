# $NetBSD: version.mk,v 1.1 2013/10/30 06:18:10 dholland Exp $

LUA_VERSION=	5.2.2

LUA_VERSION_MAJOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
LUA_VERSION_MINOR=	${LUA_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
